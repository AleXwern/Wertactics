/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:10:07 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/10 14:14:45 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include <3ds/types.h>

//might use 8 bits for stats instead.
typedef struct	s_chara
{
	u16			sprite;
	u16			strength;
	u16			magic;
	u16			defense;
	u16			resistance;
	float		speed;
}				t_chara;

typedef struct	s_growth
{
	u8			strength;
	u8			magic;
	u8			defense;
	u8			resistance;
}				t_growth;

#endif
