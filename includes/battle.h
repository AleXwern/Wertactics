/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:06:21 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/10 16:46:26 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATTLE_H
# define BATTLE_H

# define PLAYER_END			ACTIVE_SIZE
# define MAX_ENEMY			9
# define MAX_CHARA			ACTIVE_SIZE + MAX_ENEMY

typedef struct	s_battlechar
{
	u16			sprite;
	u16			x;
	u16			y;
	u8			dir;
}				t_battlechar;
# define BCHAR_SIZE		sizeof(t_battlechar) / sizeof(u16)

void			init_battle(char *id);
void			exit_battle(void);

#endif
