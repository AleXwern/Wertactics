/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:21:24 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/01 15:21:24 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"

void		render_game(t_screen *top)
{
	C2D_TargetClear(top, 0x000000ff);
	C2D_SceneBegin(top);
	draw_background();
}