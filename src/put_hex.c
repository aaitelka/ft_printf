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

int	put_hex(unsigned long decimal, char placeholder)
{
	int	counter;
	int	remainder;

	counter = 0;
	remainder = decimal % 16;
	if (decimal / 16)
		counter += put_hex(decimal / 16, placeholder);
	if (remainder < 10)
		counter += put_nbr(remainder);
	else if (remainder > 9 && placeholder == 'x')
		counter += put_char(remainder + 87);
	else if (remainder > 9 && placeholder == 'X')
		counter += put_char(remainder + 55);
	return (counter);
}
