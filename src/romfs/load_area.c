/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:59:21 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/27 15:59:21 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "area.h"

static void	set_mapdata(int fd)
{
	char	*dummy;
	char	**data;
	
	get_next_line(fd, &dummy);
	data = ft_strsplit(dummy, ',');
	free(dummy);
	g_map->width = ft_atoi(data[0]);
	g_map->height = ft_atoi(data[1]);
	ft_splitfree(data);
}

static void	unload_mapdata()
{
	if (g_map)
	{
		linearFree(g_map->tile);
		linearFree(g_map->warp);
	}
}

int			load_map(char *id)
{
	char	*path;
	int		fd;
	char	*dummy;

	path = ft_quadjoin("romfs:/maps/", id, "/area.map", "");
	free(id);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		return (1);
	unload_mapdata();
	set_mapdata(fd);
	if (!(g_map->tile = (t_tile*)linearAlloc(sizeof(t_tile) * g_map->width * g_map->height)))
		return (1);
	for (u16 y = 0; y < g_map->height; y++)
	{
		get_next_line(fd, &dummy);
		for (u16 x = 0; x < g_map->width; x++)
		{
			g_map->tile[y * g_map->width + x].type = dummy[x] - '0';
			g_map->tile[y * g_map->width + x].entity = 0;
			g_map->tile[y * g_map->width + x].warpid = 0;
		}
	}
	g_map->bg.back.id = 0;
	g_map->bg.front.id = 1;
	g_map->bg.fore.id = 2;
	printf("\x1b[4;0HMap loaded %dx%d", g_map->width, g_map->height);
	return (0);
}