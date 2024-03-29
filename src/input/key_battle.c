/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_battle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:19:00 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/27 15:56:01 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "battle.h"

static int		keys_down(void)
{
	u32			keys;
	u32			key;

	keys = hidKeysDown();
	while (keys)
	{
		key = keys & -keys;		//Extract the lowest set bit and perform switchCase with it.
		switch (key)
		{
			case KEY_START:
				exit_battle();
				return (0);
			case KEY_DDOWN:
				break;
			case KEY_DUP:
				break;
			case KEY_A:
				g_battle.actors[g_battle.chara].x = 310;
				g_battle.actors[g_battle.chara].seq.frame = 0;
				g_battle.actors[g_battle.chara].seq.anim[0] = (t_frame){.frames = 0, .x = 0};
				g_battle.chara++;
				if (g_battle.chara >= ACTIVE_SIZE)
					g_battle.chara = 0;
				g_battle.actors[g_battle.chara].seq.anim[0] = (t_frame){.frames = 5, .x = -5};
				break;
			default:
				break;
		}
		keys -= key;		//Remove the bit from "queue" and try loop again.
	}
	return (0);
}

static int		keys_held(void)
{
	u32			keys;
	u32			key;

	keys = hidKeysHeld();
	while (keys)
	{
		key = keys & -keys;		//Extract the lowest set bit and perform switchCase with it.
		switch (key)
		{
			case KEY_DUP:
				break;
			case KEY_DDOWN:
				break;
			default:
				break;
		}
		keys -= key;		//Remove the bit from "queue" and try loop again.
	}
	return (0);
}

int			key_state_battle(void)
{
	int		ret;

	ret = keys_down();
	keys_held();
	return (ret);
}
