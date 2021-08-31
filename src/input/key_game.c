/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:16:43 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/19 16:38:29 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "player.h"
#include "audio.h"
#include "gfx.h"
#include "area.h"
#include "battle.h"
#include "savegame.h"

s8	speed = 1;

static int	keys_down(void)
{
	u32	keys;
	u32	key;

	keys = hidKeysDown();
	while (keys)
	{
		key = keys & -keys;		//Extract the lowest set bit and perform switchCase with it.
		switch (key)
		{
			case KEY_START:
				exit_game();
				return (0);
			case KEY_A:
				break;
			case KEY_B:
				speed = 2;
				break;
			case KEY_Y:
				play_sfx(0, true);
				break;
			case KEY_X:
				play_sfx(1, true);
				break;
			case KEY_L:
				swap_music("romfs:/audio/bgm/str4E.ogg");
				break;
			case KEY_R:
				swap_music("romfs:/audio/bgm/finboss.ogg");
				break;
			case KEY_SELECT:
				save_game();
			default:
				break;
		}
		keys -= key;		//Remove the bit from "queue" and try loop again.
	}
	return (0);
}

static int	keys_up(void)
{
	u32	keys;
	u32	key;

	keys = hidKeysUp();
	while (keys)
	{
		key = keys & -keys;		//Extract the lowest set bit and perform switchCase with it.
		switch (key)
		{
			case KEY_B:
				speed = 1;
				break;
			default:
				break;
		}
		keys -= key;		//Remove the bit from "queue" and try loop again.
	}
	return (0);
}

static int	keys_held(void)
{
	u32		keys;
	u32		key;
	bool	moved;

	if (g_player.lock.check)
		return (0);
	keys = hidKeysHeld();
	moved = 0;
	while (keys)
	{
		key = keys & -keys;		//Extract the lowest set bit and perform switchCase with it.
		switch (key)
		{
			case KEY_DLEFT:
				g_player.direction = NPC_DIR_LEFT;
				if (g_player.x == 0 ||
					g_map->tile[g_player.y * g_map->width + (g_player.x - 1)].type)
					break;
				g_player.x--;
				g_player.lock.xy.x = 20;
				moved = 1;
				break;
			case KEY_DRIGHT:
				g_player.direction = NPC_DIR_RIGHT;
				if (g_player.x == g_map->width - 1 ||
					g_map->tile[g_player.y * g_map->width + (g_player.x + 1)].type)
					break;
				g_player.x++;
				g_player.lock.xy.x = -20;
				moved = 1;
				break;
			case KEY_DUP:
				g_player.direction = NPC_DIR_BACK;
				if (g_player.y == 0 ||
					g_map->tile[(g_player.y - 1) * g_map->width + g_player.x].type)
					break;
				g_player.y--;
				g_player.lock.xy.y = 20;
				moved = 1;
				break;
			case KEY_DDOWN:
				g_player.direction = NPC_DIR_FRONT;
				if (g_player.y == g_map->height - 1 ||
					g_map->tile[(g_player.y + 1) * g_map->width + g_player.x].type)
					break;
				g_player.y++;
				g_player.lock.xy.y = -20;
				moved = 1;
				break;
			default:
				break;
		}
		keys -= key;		//Remove the bit from "queue" and try loop again.
	}
	if (moved)
	{
		try_load_warp();
		randomx_seed(g_player.y * g_player.x - g_player.direction);
		g_player.aggro += 1;
	}
	return (0);
}

int			key_state_game(void)
{
	int		ret;

	ret = keys_down();
	keys_held();
	keys_up();
	if ((g_player.lock.xy.x & 1) == 0 && (g_player.lock.xy.y & 1) == 0)
		g_player.speed = speed;
	if (g_player.aggro >= g_player.maxaggro)
	{
		g_player.lock.check = 0;
		init_battle(ft_itoa(0));	//Encounter array
	}
	return (ret);
}
