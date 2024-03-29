/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:59:47 by anystrom          #+#    #+#             */
/*   Updated: 2021/08/05 18:31:24 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 32
# define MAX_FD 8192

int		get_first_line(const int fd, char **line);
int		get_next_line(const int fd, char **line);

//Special implementation for Wertactics
int		get_next_lineg(const int fd, char **line);
void	clear_next_line(const int fd);

#endif
