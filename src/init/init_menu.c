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
	menu->size = ft_listlen(menu->text);
	for (size_t i = 0; i < MENU_GFX_COUNT; i++)
	{
		C2D_SpriteFromSheet(&menu->gfx[menutype + i], g_msheet, i);
		C2D_SpriteSetCenter(&menu->gfx[menutype + i], 0, 0);
        C2D_SpriteSetPos(&menu->gfx[menutype + i], 0, 0);
	}
	menu->padding = 0;
	C2D_PlainImageTint(&menu->tint, 0xdce31e, 0.25f);
}

void		init_menu(void)
{
	g_msheet = C2D_SpriteSheetLoad("FILE");
}
