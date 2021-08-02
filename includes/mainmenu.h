/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainmenu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:30:11 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/02 14:30:11 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINMENU_H
# define MAINMUNU_H

#include "tactics.h"
#include "menu.h"

#define MM_GFX_COUNT	4
#define MM_KEY_COOLDOWN	20

typedef struct	s_mainmenu
{
	t_menu		mm;
	u8			sequence;	//cutscene sequence before the actual menu
	u8			subseq;		//0-fadein, 1-still, 2-fadeout
	u8			frame;		//frame of subseq;
}				t_mainmenu;

extern t_mainmenu	g_menu;

#endif
