/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:06:05 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/11 22:06:05 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_gfxdim		g_bgDim[] = {
    {.width = 425, .height = 240},
    {.width = 572, .height = 240},
	//{.width = 760, .height = 260},
    {.width = 868, .height = 240}
};
C2D_Sprite		*g_backgrounds = NULL;

C2D_Sprite		*g_npcs = NULL;
