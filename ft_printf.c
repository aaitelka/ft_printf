/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:40:29 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/17 15:05:53 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

static void check_format(va_list ap, const char *format)
{
    while (*format) {
        if (*format == '%')
        {
            format++;
            if (*format == '%' && format++)
                put_char('%', 1);
            else if (*format == 'c' && format++)
                put_char(va_arg(ap, int), 1);
            else if (*format == 's' && format++)
                put_str((char *) va_arg(ap, char*), 1);
            else if ((*format == 'd' || *format == 'i')  && format++)
                put_nbr((int) va_arg(ap, int), 1);
            else if (*format == 'u' && format++)
                put_nbr( va_arg(ap, unsigned int), 1);
            else if ((*format == 'x' || *format == 'X'))
                put_hex((long)va_arg(ap, long), 16, *format++);
            else if (*format == 'p' && format++) {
                put_str("0x", 1);
                put_hex((unsigned long) va_arg(ap, long), 16, 'x');
            }
        } else
            put_char(*format++, 1);
    }
}

int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    check_format(args, format);
    va_end(args);
    return (0);
}
