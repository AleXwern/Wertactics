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

typedef enum
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT
}				e_direction;

typedef struct	s_player
{
	u16			x;
	u16			y;
	s8			lock;
	e_npcDir	direction;
	e_npcSprite	sprite;
	s8			speed;
}				t_player;
extern t_player	g_player;

#endif