/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:55:17 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/27 15:55:17 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AREA_H
# define AREA_H

# include "tactics.h"
# include "gfx.h"

typedef struct		s_tile
{
	u8				type;		//Type of terrain. ex. walkable or not
	u8				warpid	: 7;//if has warp, specify where it leads
	u8				entity	: 1;//if the tile has entity in it.
}					t_tile;

typedef struct		s_warp
{
	u8				id;			//destination id
	u16				x;			//destination X coord
	u16				y;			//destination Y coord
}					t_warp;

typedef struct		s_area
{
	u16				width;		//width of the map
	u16				height;		//height of the map
	u8				warpcount;
	t_background	bg;			//background graphics and flags
	t_tile			*tile;		//list of all the tiles
	t_warp			*warp;		//list of all the warps
}					t_area;

extern t_area		*g_map;

#endif