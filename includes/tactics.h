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

# define TOP_X		400
# define TOP_Y		240

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

void	draw_background();
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

int		load_map(char *id);

#endif
