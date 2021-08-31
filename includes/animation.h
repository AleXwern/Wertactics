/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:57:49 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/27 14:51:59 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

#include <3ds/types.h>

typedef struct	s_frame
{
	u16			frames;		//How many frames this animation will be played
	s8			x;			//character pos X change
	s8			y;			//character pos Y change
}				t_frame;

typedef struct	s_seq
{
	u16			frame;		//How many frames have played
	t_frame		anim[3];	//framesequence
}				t_seq;

#endif
