/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_battle_gfx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:59:16 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/18 15:22:18 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "gfx.h"
#include "battle.h"

C2D_SpriteSheet	g_foesheet = NULL;
C2D_SpriteSheet	g_bbgsheet = NULL;

void		unload_enemies(void)
{
	C2D_SpriteSheetFree(g_foesheet);
	g_foesheet = NULL;
	C2D_SpriteSheetFree(g_bbgsheet);
	g_bbgsheet = NULL;
}

bool		load_enemies(void)
{
	g_foesheet = C2D_SpriteSheetLoad("romfs:/gfx/enemy.t3x");
	if (!g_foesheet)
		exit_out(SHEET_ERROR);
	g_bbgsheet = C2D_SpriteSheetLoad("romfs:/gfx/battlebg.t3x");
	if (!g_bbgsheet)
		exit_out(SHEET_ERROR);
	return (true);
}

void		get_enemy_sprites(C2D_Sprite *sprite, t_btlchar *data)
{
	for (u8 i = 0; i < MAX_ENEMY; i++)
	{
		C2D_SpriteFromSheet(&sprite[i], g_foesheet, data[i].sprite);
		C2D_SpriteSetCenter(&sprite[i], 0.5f, 0.5f);
	}
}

void		get_battle_bg(C2D_Sprite *bg, u16 id)
{
	C2D_SpriteFromSheet(bg, g_bbgsheet, id);
	C2D_SpriteSetCenter(bg, 0, 0);
	C2D_SpriteSetPos(bg, 0, 0);
}
