/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfx[id].c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:10:00 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/31 15:10:00 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "audio.h"

//High priority SFX used in most places like menus. Do not remove unless really needed.
Mix_Chunk	*g_sfx[SFX_COUNT];
//Low priority SFX used in spesific cases. Load when needed and remove after.
u16			g_count;
Mix_Chunk	**g_lsfx;

int			load_prio_sfx(char **path)
{
	for (u16 i = 0; i < SFX_COUNT; i++)
	{
		g_sfx[i] = Mix_LoadWAV(path[i]);
	}
	ft_splitfree(path);
	return (1);
}

int			load_sfx(const char *path)
{
	g_lsfx[g_count] = Mix_LoadWAV(path);
	g_count++;
	if (g_count % 10 == 0)
		g_lsfx = (Mix_Chunk**)realloc(g_lsfx, sizeof(Mix_Chunk*) * (g_count + 10));
	return (1);
}

void		unload_sfx(u16 id)
{
	for (u16 i = 0; i < g_count; i++)
		Mix_FreeChunk(g_lsfx[i]);
	g_lsfx = (Mix_Chunk**)realloc(g_lsfx, sizeof(Mix_Chunk*) * 10);
}

void		init_sfx(void)
{
	g_lsfx = (Mix_Chunk**)ft_memalloc(sizeof(Mix_Chunk*) * 10);
	g_count = 0;
}

int			play_sfx(u16 id, bool prio)
{
	static u8	chn;

	if (chn < 1 || chn >= MAX_CHANNELS)
		chn = 1;
	if (prio)
		Mix_PlayChannel(chn, g_sfx[id], 0);
	else
		Mix_PlayChannel(chn, g_lsfx[id], 0);
	chn++;
	return (1);
}
