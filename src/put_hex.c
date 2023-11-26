/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:02:42 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/26 22:00:03 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	put_hex(unsigned long decimal, int base, char placeholder)
{
	int				counter;
	unsigned long	remainder;

	counter = 0;
	remainder = decimal % base;
	if (decimal / base)
		counter += put_hex(decimal / base, base, placeholder);
	if (remainder < 10)
		counter += put_nbr((long) remainder);
	else if ((long) remainder > 9 && placeholder == 'x')
		counter += put_char(remainder + 87);
	else if ((long) remainder > 9 && placeholder == 'X')
		counter += put_char(remainder + 55);
	return (counter);
}
