/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:53:56 by AleXwern          #+#    #+#             */
/*   Updated: 2021/01/02 14:53:56 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"

int				main(void)
{
	if (init_all())
		ft_putendl("Inizialized systems!");
	if (!load_backgrounds())
		exit_out("Couldn't load backdrops!");
	if (!load_PlayerNPC())
		exit_out("Couldn't load npcs!");
	g_map = (t_area*)linearAlloc(sizeof(t_area));
	if (load_map(ft_itoa(0), 1, 1))
		exit_out("Map error");
	if (!load_music("romfs:/str4E.ogg"))
		printf("\x1b[14;0HWääää\n");
	load_sfx("romfs:/eff0.wav", 0);
	load_sfx("romfs:/eff1.wav", 1);
	game_loop();
	exit_out("Graceful exit.");
	return 0;
}
