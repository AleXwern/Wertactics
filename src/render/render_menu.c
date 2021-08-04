/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:30:06 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/03 15:30:06 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

/*
**	TODO: Scaleable menus -> ATM all menus are 250x40
*/
void			render_menu(t_menu *menu)
{
	u16			x;
	u16			y;
	C2D_TextBuf	buffer;
	C2D_Text	text;

	x = menu->x;
	buffer = C2D_TextBufNew(MENU_MAX_GLYPH);
	for (u16 i = 0; i < menu->size; i++)
	{
		y = menu->y + (MENU_DIM_Y + menu->padding) * i;
		C2D_SpriteSetPos(&menu->gfx[1], x, y);
		if (i == menu->cursor)
			C2D_DrawSpriteTinted(&menu->gfx[1], &menu->tint);
		else
			C2D_DrawSprite(&menu->gfx[1]);
		C2D_TextParse(&text, buffer, menu->text[i]);
		//C2D_TextOptimize(&text);
		C2D_DrawText(&text, 0, x + 40, y + 5, 0.0f, 1.0f, 1.0f);
	}
	C2D_TextBufDelete(buffer);
}
