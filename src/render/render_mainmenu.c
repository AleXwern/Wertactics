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
	C2D_TargetClear(top, 0x000000ff);
	C2D_SceneBegin(top);
}

void	init_mm_sequence()
{
	ft_bzero(&g_menu, sizeof(g_menu));
	if (!(g_menugfx = (C2D_Sprite*)malloc(sizeof(C2D_Sprite) * MM_GFX_COUNT)))
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
	set_gameloop(render_mainmenu, key_state_mm);
}

void	exit_mm_sequence()
{
	ft_bzero(&g_menu, sizeof(g_menu));
	C2D_SpriteSheetFree(g_mmsheet);
	free(g_menugfx);
	g_menugfx = NULL;
}
