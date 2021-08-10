/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:04:37 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/26 14:04:37 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <3ds.h>
# include "gfx.h"
# include "character.h"

# define PARTY_SIZE		10
# define ACTIVE_SIZE	5

typedef struct	s_player
{
	u16			x;
	u16			y;
	union		u_lock
	{
		s16		check;
		struct	s_lock
		{
			s8	x;
			s8	y;
		}		xy;
	}			lock;
	u8			direction;
	e_npcSprite	sprite;
	s8			speed;
}				t_player;

extern t_player	g_player;
extern t_chara	g_party[PARTY_SIZE];
extern t_chara	*g_active[ACTIVE_SIZE];

#endif
