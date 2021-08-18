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

//Libft related headers
# include "libft.h"
# include "libax.h"
//Libraries/libC
# include <3ds.h>
# include <citro2d.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
//Headers related to this project
# include "audio.h"
# include "error.h"

# define TOP_X_2	200
# define TOP_X		400
# define TOP_Y_2	120
# define TOP_Y		240

typedef C3D_RenderTarget t_screen;

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

int		exit_all(void);
int		init_all(void);
void	init_mm_sequence(void);
void	exit_mm_sequence(void);
void	init_game(void);
void	exit_game(void);

void	draw_background(void);
t_gfx	read_bmp(char *file, int fd, int bread);

void	exit_out(const char *msg);
void	signal_out(int signal);

void	game_loop(void);
void	set_gameloop(void (*top)(t_screen*),
					void (*bottom)(t_screen*),
					int (*keyhandle)(void));
void	render_game(t_screen *top);
void	render_game_bottom(t_screen *bottom);
int		key_state_battle(void);
int		key_state_game(void);
int		key_state_mm(void);

int		load_map(char *id, u16 x, u16 y);
void	try_load_warp(void);

void	randomx_seed(u64 seed);
u32		randomx(void);

#endif
