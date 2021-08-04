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

static void	unload_mapdata(void)
{
	if (g_map)
	{
		free(g_map->tile);
		free(g_map->warp);
	}
}

void		load_warps(int fd)
{
	char	*dummy;
	char	**warp;
	u16		x;
	u16		y;

	if (get_next_line(fd, &dummy))
		free(dummy);
	else
		return;
	g_map->warpcount = 0;
	while (get_next_line(fd, &dummy))
	{
		warp = ft_strsplit(dummy, ',');
		g_map->warp[g_map->warpcount].id = ft_atoi(warp[2]);
		g_map->warp[g_map->warpcount].x = ft_atoi(warp[3]);
		g_map->warp[g_map->warpcount].y = ft_atoi(warp[4]);
		x = ft_atoi(warp[0]);
		y = ft_atoi(warp[1]);
		g_map->tile[y * g_map->width + x].warpid = g_map->warpcount + 1;	//warp index 0 is 1 so we can treat 0 in map as none
		ft_splitfree(warp);
		g_map->warpcount++;
		if (g_map->warpcount % 10 == 0)
			g_map->warp = (t_warp*)realloc(g_map->warp, sizeof(t_warp) * (g_map->warpcount + 10));
	}
	g_map->warp = (t_warp*)realloc(g_map->warp, sizeof(t_warp) * g_map->warpcount);
}

int			load_map(char *id, u16 x, u16 y)
{
	char	*path;
	int		fd;
	char	*dummy;

	path = ft_quadjoin("romfs:/maps/", id, "/area.map", "");
	free(id);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
	{
		printf("\x1b[10;0HCouldn't load map\n");
		return (1);
	}
	unload_mapdata();
	set_mapdata(fd);
	if (!(g_map->tile = (t_tile*)ft_memalloc(sizeof(t_tile) * g_map->width * g_map->height)))
		exit_out(MALLOC_ERROR);
	if (!(g_map->warp = (t_warp*)ft_memalloc(sizeof(t_warp) * 10)))
		exit_out(MALLOC_ERROR);
	for (u16 y = 0; y < g_map->height; y++)
	{
		get_next_line(fd, &dummy);
		for (u16 x = 0; x < g_map->width; x++)
		{
			g_map->tile[y * g_map->width + x].type = dummy[x] - '0';
			g_map->tile[y * g_map->width + x].entity = 0;
			g_map->tile[y * g_map->width + x].warpid = 0;
		}
		free(dummy);
	}
	load_warps(fd);
	g_map->bg.back.id = 0;
	g_map->bg.front.id = 1;
	g_map->bg.fore.id = 2;
	g_player.x = x;
	g_player.y = y;
	g_player.lock.xy.x = 0;
	g_player.lock.xy.y = 0;
	close(fd);
	printf("\x1b[4;0HMap loaded %dx%d", g_map->width, g_map->height);
	return (0);
}

void		try_load_warp()
{
	u8		warp;

	warp = g_map->tile[g_player.y * g_map->width + g_player.x].warpid;
	if (warp)
		load_map(ft_itoa(g_map->warp[warp - 1].id), 
						g_map->warp[warp - 1].x,
						g_map->warp[warp - 1].y);
	return;
}
