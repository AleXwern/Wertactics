/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:17:18 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/02 16:17:18 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

C2D_SpriteSheet	g_msheet = NULL;

void		set_menu(t_menu *menu, const char *path, e_menutype menutype)
{
	int		fd;
	char	*text;

	fd = open(path, O_RDONLY | O_BINARY);
	get_next_line(fd, &text);
	menu->text = ft_strsplit(text, ',');
	free(text);
	menu->size = ft_listlen(menu->text) - 1;
	for (size_t i = 0; i < MENU_GFX_COUNT; i++)
	{
		C2D_SpriteFromSheet(&menu->gfx[menutype + i], g_msheet, i);
		C2D_SpriteSetCenter(&menu->gfx[menutype + i], 0, 0);
        C2D_SpriteSetPos(&menu->gfx[menutype + i], 0, 0);
	}
	close(fd);
	menu->padding = 0;
	C2D_PlainImageTint(&menu->tint, 0xffdce31e, 0.25f);
}

void		clear_menu(t_menu *menu)
{
	ft_splitfree(menu->text);
}

/*
**	Different menu graphics are loaded into memory where they can be fetched easily as needed.
**	Freeing is maybe not needed as it's freed anyway when program closes.
**	If there happends to be some weird quirk in 3DS OS then I'll be a good boy and clean after me.
*/
void		init_menu(void)
{
	g_msheet = C2D_SpriteSheetLoad("romfs:/gfx/menus.t3x");
}
