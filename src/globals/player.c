/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:25:37 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/26 18:25:37 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	g_player = (t_player){
	.x = 1, 
	.y = 1, 
	.lock.check = 0,
	.direction = NPC_DIR_LEFT,
	.sprite = 0,
	.speed = 1
};
t_chara	g_party[] = {0};
t_chara	*g_active[] = {NULL, NULL, NULL, NULL};
