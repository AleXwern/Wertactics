/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:43:05 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/02 15:43:05 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "mainmenu.h"

static int		check_newstate(u16 cursor)
{
	switch (cursor)
	{
		case MM_CONTINUE:
			init_game();
			break;
		case MM_LEVEL_EDITOR:
			return (0);
		case MM_EXIT:
			return (1);
		default:
			return (0);
	}
	return (0);
}

static int		keys_down(void)
{
	u32			keys;
	u32			key;

	keys = hidKeysDown();
	while (keys)
	{
		key = keys & -keys;		//Extract the lowest set bit and perform switchCase with it.
		if (g_menu.sequence < 3)
		{
			switch (key)
			{
				case KEY_START:
					return (1);
				case KEY_A:
					g_menu.sequence++;
					g_menu.frame = 0;
					g_menu.subseq = 0;
					break;
				default:
					break;
			}
		}
		else
		{
			switch (key)
			{
				case KEY_START:
					return (1);
				case KEY_DDOWN:
					g_menu.mm.cursor++;
					break;
				case KEY_DUP:
					g_menu.mm.cursor--;
					break;
				case KEY_A:
					return (check_newstate(g_menu.mm.cursor));
				default:
					break;
			}
		}
		keys -= key;		//Remove the bit from "queue" and try loop again.
	}
	return (0);
}

static int		keys_held(void)
{
	u32			keys;
	u32			key;
	static u8	cooldown;
	bool		noreset;

	keys = hidKeysHeld();
	noreset = 0;
	while (keys)
	{
		key = keys & -keys;		//Extract the lowest set bit and perform switchCase with it.
		switch (key)
		{
			case KEY_DUP:
				if (cooldown < MM_KEY_COOLDOWN)
					cooldown++;
				else
					g_menu.mm.cursor++;
				noreset = true;
				break;
			case KEY_DDOWN:
				if (cooldown < MM_KEY_COOLDOWN)
					cooldown++;
				else
					g_menu.mm.cursor--;
				noreset = true;
				break;
			default:
				break;
		}
		keys -= key;		//Remove the bit from "queue" and try loop again.
	}
	if (!noreset)
		cooldown = 0;
	return (0);
}

int			key_state_mm(void)
{
	int		ret;

	ret = keys_down();
	keys_held();
	if (g_menu.mm.cursor > 0xefff)
		g_menu.mm.cursor = g_menu.mm.size - 1;
	else if (g_menu.mm.cursor == g_menu.mm.size)
		g_menu.mm.cursor = 0;
	return (ret);
}
