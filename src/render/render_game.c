/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:21:24 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/01 15:21:24 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "gfx.h"
#include "player.h"

void		render_game(t_screen *top)
{
	C2D_TargetClear(top, 0x000000ff);
	C2D_SceneBegin(top);
	draw_background();
}

void		render_game_bottom(t_screen *bottom)
{
	return;
}

void		init_game(void)
{
	exit_mm_sequence();
	set_gameloop(render_game, render_game_bottom, key_state_game);
	if (load_map(ft_itoa(0), 1, 1))
		exit_out(MAP_ERROR);
	load_backgrounds();
	load_PlayerNPC(NPC_SPR_GIRL);
	g_player.maxaggro = randomx() % 50 + 20;
}

/*
**	There's probably more here that I don't understand (Which is REALLY bad to be honest)
**	init MM needs to be first or I load bad graphics into memory sometimes.
*/
void		exit_game(void)
{
	init_mm_sequence();
	unload_backgrounds();
	unload_playerNPC();
}
