/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:35:03 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/23 14:00:22 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "savegame.h"

void	load_game(void)
{
	int	fd;
	u64	sav;

	fd = open("sdmc:/3ds/wer60.sav", O_RDONLY | O_BINARY);
	if (fd == -1)
		return;
	sav = 0;
	read(fd, &sav, sizeof(SAVE_VERSION));
	if (sav != SAVE_VERSION)
	{
		close(fd);
		return;
	}
	read(fd, &g_player, sizeof(g_player));
	read(fd, &g_party, sizeof(g_party));
	close(fd);
	printf("\x1b[7;0HLoaded save\n");
}
