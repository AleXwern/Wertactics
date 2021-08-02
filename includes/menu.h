/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:03:47 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/02 16:03:47 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

#include "tactics.h"

# define MENU_GFX_COUNT	3

typedef enum
{
	MENU_MM = 0
}					e_menutype;

typedef struct		s_menu
{
	u16				size;
	u16				cursor;
	u16				minshown;
	u8				padding;
	C2D_Sprite		gfx[MENU_GFX_COUNT];
	char			**text;
	C2D_ImageTint	tint;
}					t_menu;

void	init_menu(void);
void	set_menu(t_menu *menu, const char *path, e_menutype menutype);

#endif
