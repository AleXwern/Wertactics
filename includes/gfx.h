/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:06:19 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/11 22:06:19 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include <3ds.h>
# include "tactics.h"

typedef struct  s_gfxdim
{
    s16         width;
    s16         height;
}               t_gfxdim;

extern t_gfxdim     g_bgDim[];
extern C2D_Sprite   *g_backgrounds;

typedef enum
{
	NPC_SPRDIM_X_2 =	10,
	NPC_SPRDIM_X =		NPC_SPRDIM_X_2 * 2 - 1, //Make sprite dimensions better
	NPC_SPRDIM_Y_2 =	10,
	NPC_SPRDIM_Y =		NPC_SPRDIM_Y_2 * 2,
}               e_npcSpriteDim;

typedef enum
{
	NPC_SPR_DOG
}               e_npcSprite;

typedef enum
{
	NPC_DIR_FRONT = 0,
	NPC_DIR_BACK =	3,
	NPC_DIR_LEFT =	6,
	NPC_DIR_RIGHT =	9
}				e_npcDir;
extern t_gfxdim     g_npcDim[];
extern C2D_Sprite   *g_npcs;

#endif