/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:55:32 by AleXwern          #+#    #+#             */
/*   Updated: 2021/01/02 14:55:32 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICS_H
# define TACTICS_H

# include "libft.h"
# include "libax.h"
# include <3ds.h>
# include <citro2d.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define TOP_X		400
# define TOP_Y		240

# define NUM_SPRITES	3
# define NUM_NPC_SPRITES	12

typedef struct	s_gfx
{
	u32			*data;
	int			wid;
	int			hgt;
	int			pitch;
	int			bpp;
	int			x;
	int			y;
}				t_gfx;

typedef enum
{
	EFF_SCROLL_NONE =	0,
	EFF_SCROLL_WPLR =	(1 << 0),
	EFF_SCROLL_RIGHT =	(1 << 1),
	EFF_SCROLL_LEFT =	(1 << 2),
	EFF_SCROLL_UP =		(1 << 3),
	EFF_SCROLL_DOWN =	(1 << 4),
	EFF_SCROLL_BLEND =	(1 << 5),
	EFF_SCROLL_REV =	(1 << 6)
}				e_bgEffect;

typedef struct	s_bg
{
	u16			id;
	e_bgEffect	effect;
}				t_bg;

typedef struct	s_background
{
	t_bg		back;
	t_bg		front;
	t_bg		fore;
}				t_background;

int		exit_all(void);
int		init_all(void);

void	draw_background(t_background *bg);
t_gfx	read_bmp(char *file, int fd, int bread);

void	exit_out(const char *msg);

bool	load_backgrounds();
bool	load_PlayerNPC();
int		key_state_game(void);

void	audio_load(void);
void	audio_stop(void);
void	audio_swap(const char *file);

void	play_effect(u8 id);
void	load_effect(const char *path, u8 id);

#endif
