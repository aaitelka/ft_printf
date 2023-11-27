/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:40:29 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/27 10:25:56 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

static int	check_hex(va_list ap, char placeholder)
{
	int	counter;

	counter = 0;
	counter += put_str("0x");
	counter += put_hex((unsigned long) va_arg(ap, long), placeholder);
	return (counter);
}

static int	check_format(va_list ap, const char *format, int counter)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%' && format++)
				counter += put_char('%');
			else if (*format == 'c' && format++)
				counter += put_char(va_arg(ap, int));
			else if (*format == 's' && format++)
				counter += put_str((char *) va_arg(ap, char *));
			else if ((*format == 'd' || *format == 'i') && format++)
				counter += put_nbr((int) va_arg(ap, int));
			else if (*format == 'u' && format++)
				counter += put_nbr(va_arg(ap, unsigned int));
			else if (*format == 'x' || *format == 'X')
				counter += put_hex(va_arg(ap, unsigned int), *format++);
			else if (*format == 'p' && *format++)
				counter += check_hex(ap, 'x');
		}
		else
			counter += put_char(*format++);
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		printed_count;
	va_list	args;

	printed_count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	printed_count = check_format(args, format, printed_count);
	va_end(args);
	return (printed_count);
}
