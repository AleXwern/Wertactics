/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:16:43 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/26 14:16:43 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "player.h"

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
				return (1);
			case KEY_A:
				printf("\x1b[7;0HPressed A\n");
				break;
			case KEY_B:
				speed = 2;
				break;
			case KEY_Y:
				play_effect(0);
				break;
			case KEY_X:
				play_effect(1);
				break;
			case KEY_DUP:
				audio_swap("romfs:/str4E.wav");
				break;
			case KEY_DDOWN:
				audio_swap("romfs:/finboss.wav");
				break;
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
	u32	keys;
	u32	key;

	if (g_player.lock)
		return (0);
	keys = hidKeysHeld();
	while (keys)
	{
		key = keys & -keys;		//Extract the lowest set bit and perform switchCase with it.
		switch (key)
		{
			case KEY_DLEFT:
				g_player.x--;
				g_player.direction = NPC_DIR_LEFT;
				g_player.lock = 18;
				printf("\x1b[7;0HPosX %05u\n", g_player.x);
				break;
			case KEY_DRIGHT:
				g_player.x++;
				g_player.direction = NPC_DIR_RIGHT;
				g_player.lock = -18;
				printf("\x1b[7;0HPosX %05u\n", g_player.x);
				break;
			default:
				break;
		}
		keys -= key;		//Remove the bit from "queue" and try loop again.
	}
	return (0);
}

int			key_state_game(void)
{
	int		ret;

	ret = keys_down();
	keys_held();
	keys_up();
	if (g_player.lock % 2 == 0)
		g_player.speed = speed;
	return (ret);
}
