/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:06:21 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/18 15:15:39 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATTLE_H
# define BATTLE_H

# include <3ds/types.h>
# include "player.h"

# define PLAYER_END			ACTIVE_SIZE
# define MAX_ENEMY			9
# define MAX_CHARA			ACTIVE_SIZE + MAX_ENEMY

typedef struct	s_btlchar
{
	u16			sprite;
	u16			x;
	u16			y;
	u8			dir;
}				t_btlchar;

typedef struct	s_battle
{
	t_btlchar	actors[MAX_CHARA];
	u8			chara;
	u8			count;
}				t_battle;

void			init_battle(char *id);
void			exit_battle(void);
void			get_battle_bg(C2D_Sprite *bg, u16 id);
void			get_enemy_sprites(C2D_Sprite *sprite, t_btlchar *data);

#endif
