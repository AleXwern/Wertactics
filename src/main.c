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
	g_map = (t_area*)linearAlloc(sizeof(t_area));
	if (!load_music("romfs:/str4E.ogg"))
		printf("\x1b[14;0HWääää\n");
	load_sfx("romfs:/eff0.wav", 0);
	load_sfx("romfs:/eff1.wav", 1);
	game_loop();
	exit_out(NO_ERROR);
	return 0;
}
