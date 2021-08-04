/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mainmenu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:27:10 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/02 14:27:10 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "mainmenu.h"

t_mainmenu	g_menu;
C2D_Sprite	*g_menugfx = NULL;
C2D_SpriteSheet	g_mmsheet = NULL;	//I don't like this being here but I'll do it this way so I have a way to remove it

void	render_mainmenu(t_screen *top)
{
	C2D_ImageTint	tint;
	float			blend;

	C2D_TargetClear(top, 0xff000000);
	C2D_SceneBegin(top);
	if (g_menu.sequence == 3)
	{
		C2D_DrawSprite(&g_menugfx[3]);
		render_menu(&g_menu.mm);
	}
	else
	{
		switch (g_menu.subseq)
		{
			case 0:
				blend = 1 - (g_menu.frame / 60.0);
				break;
			case 1:
				blend = 0;
				break;
			default:
				blend = g_menu.frame / 60.0;
				break;
		}
		C2D_PlainImageTint(&tint, 0xff000000, blend);
		C2D_DrawSpriteTinted(&g_menugfx[g_menu.sequence], &tint);
		g_menu.frame++;
		if (g_menu.frame >= 60)
		{
			g_menu.subseq++;
			g_menu.frame = 0;
		}
		if (g_menu.subseq >= 3)
		{
			g_menu.sequence++;
			g_menu.subseq = 0;
		}
	}
}

void	init_mm_sequence(void)
{
	ft_bzero(&g_menu, sizeof(g_menu));
	if (!(g_menugfx = (C2D_Sprite*)ft_memalloc(sizeof(C2D_Sprite) * MM_GFX_COUNT)))
		exit_out(MALLOC_ERROR);
	if (!(g_mmsheet = C2D_SpriteSheetLoad("romfs:/gfx/mm.t3x")))
		exit_out(MM_ERROR);
	for (size_t i = 0; i < MM_GFX_COUNT; i++)
	{
		C2D_SpriteFromSheet(&g_menugfx[i], g_mmsheet, i);
		C2D_SpriteSetCenter(&g_menugfx[i], 0, 0);		//0 pos/center is probably the default but doesn't hurt either to make sure.
        C2D_SpriteSetPos(&g_menugfx[i], 0, 0);
	}
	set_menu(&g_menu.mm, "romfs:/menutext/mm.txt", MENU_MM);
	g_menu.mm.x = 100;
	g_menu.mm.y = 70;
	g_menu.mm.padding = 20;
	set_gameloop(render_mainmenu, key_state_mm);
}

void	exit_mm_sequence(void)
{
	clear_menu(&g_menu.mm);
	ft_bzero(&g_menu, sizeof(g_menu));
	C2D_SpriteSheetFree(g_mmsheet);
	g_mmsheet = NULL;
	free(g_menugfx);
	g_menugfx = NULL;
}
