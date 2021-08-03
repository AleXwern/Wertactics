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
# define MENU_MAX_GLYPH	32

typedef enum
{
	MENU_MM = 0
}					e_menutype;

typedef enum
{
	MENU_DIM_X = 250,
	MENU_DIM_Y = 40
}					e_menugfxdim;

typedef struct		s_menu
{
	u16				x;				//X position
	u16				y;				//Y position
	u16				size;			//How many enties the menu has
	u16				cursor;			//Current cursor position
	u16				minshown;		//First rendered entry
	u8				padding;		//Padding between entries
	char			**text;			//List of text
	C2D_Sprite		gfx[MENU_GFX_COUNT];
	C2D_ImageTint	tint;			//Cursor color
}					t_menu;

void	clear_menu(t_menu *menu);
void	init_menu(void);
void	render_menu(t_menu *menu);
void	set_menu(t_menu *menu, const char *path, e_menutype menutype);

#endif
