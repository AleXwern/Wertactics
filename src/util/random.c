/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:13:25 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/12 15:33:50 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"

u64		g_random;

void	randomx_seed(u64 seed)
{
	g_random += 1103515245 * seed + 24691;
}

u32		randomx(void)
{
	g_random += 1103515 * g_random + 24691;
	return (g_random);
}
