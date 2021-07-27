/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ax_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:46:30 by AleXwern          #+#    #+#             */
/*   Updated: 2021/01/04 13:34:43 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libax.h"

int			WSAGetLastError(void)
{
	return (errno);
}

void		WSASetLastError(int err)
{
	errno = err;
}

int			ax_send(t_socket *sock, const void *data, int len)
{
	uint8_t	*letter;
	int		sent;
	int		left;

	if (sock->server)
		return (-1);
	letter = (uint8_t*)data;
	left = len;
	sent = 0;
	while (left > 0 && len > 0)
	{
		len = send(sock->channel, letter, left, 0);
		if (len > 0)
		{
			sent += len;
			left -= len;
			letter += len;
		}
	}
	return (sent);
}

int			ax_recv(t_socket *sock, void *data, int max)
{
	int		len;
	int		err;

	if (sock->server)
		return (-1);
	err = 0;
	WSASetLastError(err);
	len = -42;
	while (len == -42)
	{
		len = recv(sock->channel, (char*)data, max, 0);
		err = WSAGetLastError();
		if (err == EINTR)
			break ;
	}
	return (len);
}
