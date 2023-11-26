/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:15:14 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/17 13:57:28 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void	put_char(unsigned char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, sizeof(c));
}
