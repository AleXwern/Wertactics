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

bool        load_backgrounds()
{
    C2D_SpriteSheet	sheet;

    sheet = C2D_SpriteSheetLoad("romfs:/gfx/backgrounds.t3x");
    if (!sheet)
       return (false);
    g_backgrounds = (C2D_Sprite*)malloc(sizeof(C2D_Sprite) * NUM_SPRITES);
    if (!g_backgrounds)
        return (false);
    for (size_t i = 0; i < NUM_SPRITES; i++)
    {
        C2D_SpriteFromSheet(&g_backgrounds[i], sheet, i);
        C2D_SpriteSetCenter(&g_backgrounds[i], 0, 0);
        C2D_SpriteSetPos(&g_backgrounds[i], 0, 0);
    }
    printf("Loaded %u backgrounds\n", C2D_SpriteSheetCount(sheet));
    return (true);
}

bool        load_PlayerNPC()
{
    C2D_SpriteSheet	sheet;

    sheet = C2D_SpriteSheetLoad("romfs:/gfx/player.t3x");
    if (!sheet)
       return (false);
    g_npcs = (C2D_Sprite*)malloc(sizeof(C2D_Sprite) * NUM_NPC_SPRITES);
    if (!g_npcs)
        return (false);
    for (size_t i = 0; i < NUM_NPC_SPRITES; i++)
    {
        C2D_SpriteFromSheet(&g_npcs[i], sheet, i);
        C2D_SpriteSetCenter(&g_npcs[i], 0.5f, 0.5f);
        C2D_SpriteSetPos(&g_npcs[i], TOP_X / 2, TOP_Y * 0.65);
    }
    printf("Loaded %u sprites\n", C2D_SpriteSheetCount(sheet));
    return (true);
}