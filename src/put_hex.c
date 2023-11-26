/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:02:42 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/26 15:05:25 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void put_hex(unsigned long decimal, int base, char placeholder)
{
    unsigned long remainder;

    if (decimal)
    {
        remainder = decimal % base;
        decimal /= base;
        put_hex(decimal, base, placeholder);
        if (remainder > 9 && placeholder == 'x')
            put_char(remainder + 87, 1);
        else if (remainder > 9 && placeholder == 'X')
            put_char(remainder + 55, 1);
        else
            put_nbr(remainder, 1);
    }
}