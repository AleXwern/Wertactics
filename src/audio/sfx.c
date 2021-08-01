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

Mix_Chunk	*sfx[2];

int			load_sfx(const char *path, u16 id)
{
	sfx[id] = Mix_LoadWAV(path);
	return (1);
}

int			play_sfx(u16 id)
{
	static u8	chn;

	if (chn < 1 || chn >= MAX_CHANNELS)
		chn = 1;
	Mix_PlayChannel(chn, sfx[id], 0);
	chn++;
	return (1);
}
