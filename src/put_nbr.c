/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:42:45 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/16 15:43:17 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void	put_nbr(long nbr, int fd)
{
    if (nbr < 0)
    {
        put_char('-', fd);
        put_nbr(-nbr, fd);
    }
    else if (nbr > 9)
    {
        put_nbr(nbr / 10, fd);
        put_nbr(nbr % 10, fd);
    }
    else
        put_char(nbr + '0', fd);
}
