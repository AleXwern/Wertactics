/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:59:16 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/23 13:27:32 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "savegame.h"

void	save_game(void)
{
	int	fd;
	u64	sav;
	
	fd = open("sdmc:/3ds/wer60.sav", O_WRONLY | O_BINARY | O_CREAT | O_TRUNC);
	if (fd == -1)
		return;
	sav = SAVE_VERSION;
	write(fd, &sav, sizeof(SAVE_VERSION));
	write(fd, &g_player, sizeof(g_player));
	write(fd, &g_party, sizeof(g_party));
	close(fd);
	printf("\x1b[7;0HSaved save \n");
}
