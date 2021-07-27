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
# include "citro2d.h"

# define NUM_SPRITES	3
# define NUM_NPC_SPRITES	12

typedef enum
{
	EFF_SCROLL_NONE =	0,
	EFF_SCROLL_WPLR =	(1 << 0),
	EFF_SCROLL_RIGHT =	(1 << 1),
	EFF_SCROLL_LEFT =	(1 << 2),
	EFF_SCROLL_UP =		(1 << 3),
	EFF_SCROLL_DOWN =	(1 << 4),
	EFF_SCROLL_BLEND =	(1 << 5),
	EFF_SCROLL_REV =	(1 << 6)
}				e_bgEffect;

typedef struct	s_bg
{
	u16			id;
	e_bgEffect	effect;
}				t_bg;

typedef struct	s_background
{
	t_bg		back;
	t_bg		front;
	t_bg		fore;
}				t_background;

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