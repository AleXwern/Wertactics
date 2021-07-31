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

void			draw_layer(t_bg	bg, s32 x, s32 y)
{
	s32			x_orig;

	while (y > 0)
		y -= g_bgDim[bg.id].height;
	while (x > 0)
		x -= g_bgDim[bg.id].width;
	x_orig = x;
	while (y < TOP_Y)
	{
		while (x < TOP_X)
		{
			C2D_SpriteSetPos(&g_backgrounds[bg.id], x, y);
			C2D_DrawSprite(&g_backgrounds[bg.id]);
			x += g_bgDim[bg.id].width;
		}
		y += g_bgDim[bg.id].height;
		x = x_orig;
	}
}

void			draw_npcs(t_gfxdim offset)
{
	static u32	anim;
	u32			frame;;

	frame = g_player.direction + ((anim / 10) % 3);
	C2D_SpriteSetPos(&g_npcs[frame], TOP_X_2 - offset.width, TOP_Y_2 - offset.height + 35);
	C2D_DrawSprite(&g_npcs[frame]);
	printf("\x1b[9;0Hframe %lx\n", g_player.direction + ((anim / 10) % 3));
	if (g_player.lock.check)
		anim += g_player.speed;
	else
		anim = 0;
}

void			draw_background()
{
	s32			offset_x;
	s32			offset_y;
	t_gfxdim	offset;

	offset_x = -(g_player.x * NPC_SPRDIM_X + g_player.lock.xy.x) + 190;
	offset_y = -(g_player.y * NPC_SPRDIM_Y + g_player.lock.xy.y) + 145;
	offset.height = offset_y;
	offset.width = offset_x;
	if (offset_x > 0)
		offset_x = 0;
	else
		offset.width = 0;
	if (offset_y > 0)
		offset_y = 0;
	else
		offset.height = 0;
	draw_layer(g_map->bg.back, offset_x / 2, offset_y / 2);
	draw_layer(g_map->bg.front, offset_x, offset_y);
	draw_npcs(offset);	//for now just draw NPCs under the front layer.
	draw_layer(g_map->bg.fore, offset_x * 2, offset_y * 2);
	if (g_player.lock.xy.x > 0)
		g_player.lock.xy.x -= g_player.speed;
	else if (g_player.lock.xy.x < 0)
		g_player.lock.xy.x += g_player.speed;
	if (g_player.lock.xy.y > 0)
		g_player.lock.xy.y -= g_player.speed;
	else if (g_player.lock.xy.y < 0)
		g_player.lock.xy.y += g_player.speed;
}
