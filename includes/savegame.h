/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savegame.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:37:21 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/23 16:03:46 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVEGAME_H
# define SAVEGAME_H

# include "tactics.h"
# include "player.h"

/*
**	This is just a simple checksum so no weird saves get loaded.
**	I'll change the save format quite a lot so things will change.
**	Prepare to lose all your stuff all the time.
*/
# define SAVE_VERSION	(sizeof(t_player) | (sizeof(t_chara) << 8) | (0x3c42 << 16))

void	load_game(void);
void	save_game(void);

#endif
