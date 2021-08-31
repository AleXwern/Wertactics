/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:28:58 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/11 18:28:58 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"

void    exit_out(const char *msg)
{
    ft_putendl(msg);
    exit_all();
    exit(0);
}

void	signal_out(int signal)
{
	printf("\x1b[2;0HMajor error!\n");
	exit(1);
}
