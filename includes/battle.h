/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:06:21 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/27 15:47:44 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATTLE_H
# define BATTLE_H

# include <3ds/types.h>
# include "player.h"
# include "animation.h"

# define PLAYER_END			ACTIVE_SIZE
# define MAX_ENEMY			9
# define MAX_CHARA			ACTIVE_SIZE + MAX_ENEMY

typedef struct	s_btlchar
{
	t_seq		seq;			//Animations for character to be played
	u16			sprite;			//Character sprite
	u16			x;				//X position on screen
	u16			y;				//Y position on screen
	u8			dir;			//Facing direction
}				t_btlchar;

typedef struct	s_battle
{
	t_btlchar	actors[MAX_CHARA];
	u8			turn;			//Turn count since the start of fight. Show +1
	u8			chara;			//Current chosen character
	u8			count;			//number of enemies in field
}				t_battle;

extern t_battle	g_battle;

void			init_battle(char *id);
void			exit_battle(void);
void			get_battle_bg(C2D_Sprite *bg, u16 id);
void			get_enemy_sprites(C2D_Sprite *sprite, t_btlchar *data);

#endif
