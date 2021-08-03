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
# include "area.h"
# include "audio.h"
# include "bmp.h"
# include "gfx.h"
# include "player.h"
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

void	draw_background();
t_gfx	read_bmp(char *file, int fd, int bread);

void	exit_out(const char *msg);

bool	load_backgrounds(void);
bool	load_PlayerNPC(void);

void	game_loop(void);
void	set_gameloop(void (*render)(t_screen*), int (*keyhandle)(void));
void	render_game(t_screen *top);
int		key_state_game(void);
int		key_state_mm(void);

int		load_music(const char *path);
int		swap_music(const char *path);
int		load_sfx(const char *path, u16 id);
int		play_sfx(u16 id);
void	resume_music(void);

int		load_map(char *id, u16 x, u16 y);
void	try_load_warp(void);

#endif
