/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:33:11 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/11 18:33:11 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "gfx.h"
#include "battle.h"

C2D_SpriteSheet	g_bgsheet = NULL;
C2D_SpriteSheet	g_npcsheet = NULL;
C2D_SpriteSheet	g_foesheet = NULL;

void		unload_backgrounds(void)
{
	C2D_SpriteSheetFree(g_bgsheet);
	g_bgsheet = NULL;
	free(g_backgrounds);
	g_backgrounds = NULL;
}

bool		load_backgrounds(void)
{
	g_bgsheet = C2D_SpriteSheetLoad("romfs:/gfx/backgrounds.t3x");
	if (!g_bgsheet)
		exit_out(SHEET_ERROR);
	g_backgrounds = (C2D_Sprite*)ft_memalloc(sizeof(C2D_Sprite) * NUM_SPRITES);
	if (!g_backgrounds)
		exit_out(MALLOC_ERROR);
	for (size_t i = 0; i < NUM_SPRITES; i++)
	{
		C2D_SpriteFromSheet(&g_backgrounds[i], g_bgsheet, i);
		C2D_SpriteSetCenter(&g_backgrounds[i], 0, 0);
		C2D_SpriteSetPos(&g_backgrounds[i], 0, 0);
	}
	return (true);
}

void		unload_playerNPC(void)
{
	C2D_SpriteSheetFree(g_npcsheet);
	g_npcsheet = NULL;
	free(g_npcs);
	g_npcs = NULL;
}

bool		load_PlayerNPC(u16 id)
{
	g_player.sprite = id;
	g_npcsheet = C2D_SpriteSheetLoad("romfs:/gfx/girl.t3x");
	if (!g_npcsheet)
		exit_out(SHEET_ERROR);
	g_npcs = (C2D_Sprite*)malloc(sizeof(C2D_Sprite) * NUM_NPC_SPRITES);
	if (!g_npcs)
		exit_out(MALLOC_ERROR);
	for (size_t i = 0; i < NUM_NPC_SPRITES; i++)
	{
		C2D_SpriteFromSheet(&g_npcs[i], g_npcsheet, i);
		C2D_SpriteSetCenter(&g_npcs[i], 0.5f, 0.5f);
		C2D_SpriteSetPos(&g_npcs[i], TOP_X / 2, TOP_Y * 0.65);
	}
	return (true);
}

void		unload_enemies(void)
{
	C2D_SpriteSheetFree(g_foesheet);
	g_foesheet = NULL;
}

bool		load_enemies(void)
{
	g_foesheet = C2D_SpriteSheetLoad("romfs:/gfx/enemy.t3x");
	if (!g_foesheet)
		exit_out(SHEET_ERROR);
	return (true);
}

void		get_enemy_sprites(C2D_Sprite *sprite, t_battlechar *data)
{
	for (u8 i = 0; i < MAX_ENEMY; i++)
	{
		C2D_SpriteFromSheet(&sprite[i], g_foesheet, data[i].sprite);
		C2D_SpriteSetCenter(&sprite[i], 0.5f, 0.5f);
	}
}
