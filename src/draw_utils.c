/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:43:09 by AleXwern          #+#    #+#             */
/*   Updated: 2021/01/02 18:43:09 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "gfx.h"
#include "player.h"

void	draw_npcs(void);

void	draw_layer(t_bg	bg, s32 x, s32 y)
{
	while (y > 0)
		y -= g_bgDim[bg.id].height;
	while (x > 0)
		x -= g_bgDim[bg.id].width;
	while (y < TOP_Y)
	{
		while (x < TOP_X)
		{
			C2D_SpriteSetPos(&g_backgrounds[bg.id], x, 0);
			C2D_DrawSprite(&g_backgrounds[bg.id]);
			x += g_bgDim[bg.id].width;
		}
		y += g_bgDim[bg.id].height;
	}
}

void	draw_npcs(void)
{
	static u32	anim;

	C2D_DrawSprite(&g_npcs[g_player.direction + ((anim / 10) % 3)]);
	printf("\x1b[8;0Hframe %lx\n", g_player.direction + ((anim / 10) % 3));
	if (g_player.lock)
		anim += g_player.speed;
	else
		anim = 0;
}

void	draw_background(t_background *bg)
{
	s32	offset_x;
	s32	offset_y;

	offset_x = -(g_player.x * NPC_SPRDIM_X + g_player.lock) / 2;
	offset_y = -(g_player.y * NPC_SPRDIM_Y) / 2 - g_bgDim[bg->back.id].height;
	draw_layer(bg->back, offset_x, offset_y);
	offset_x = -(g_player.x * NPC_SPRDIM_X + g_player.lock);
	offset_y = -(g_player.y * NPC_SPRDIM_Y);
	draw_layer(bg->front, offset_x, offset_y);
	draw_npcs();	//for now just draw NPCs under the front layer.
	offset_x = -(g_player.x * NPC_SPRDIM_X + g_player.lock) * 2;
	offset_y = -(g_player.y * NPC_SPRDIM_Y) * 2;
	draw_layer(bg->fore, offset_x, offset_y);
	if (g_player.lock > 0)
		g_player.lock -= g_player.speed;
	else if (g_player.lock < 0)
		g_player.lock += g_player.speed;
}
