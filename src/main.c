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
	signal(SIGABRT, signal_out);
	if (init_all())
		ft_putendl("Inizialized systems!");
	if (!(g_map = (t_area*)ft_memalloc(sizeof(t_area))))
		exit_out(MALLOC_ERROR);
	game_loop();
	exit_out(NO_ERROR);
	return 0;
}
