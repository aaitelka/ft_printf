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

#include "../libft/libft.h"
#include "ft_printf.h"

static int is_format(const char *str, char *f)
{
    return (ft_strncmp(str, f, 2) == 0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    while (*format)
    {
        if (is_format(format, "%c") && format++)
        {
            ft_putchar_fd(va_arg(args, int), 1);
        }
        else if (is_format(format, "%s") && format++)
        {
            ft_putstr_fd((char*)va_arg(args, char*), 1);
        }
        else if (is_format(format, "%p") && format++)
        {
            ft_putnbr_fd((int)va_arg(args, int), 1);
        }
        else if ((is_format(format, "%d") || (is_format(format,  "%i"))) && format++)
        {
            ft_putnbr_fd((int)va_arg(args, int), 1);
        }
        else if(is_format(format, "%%"))
        {
            ft_putchar_fd(va_arg(args, int), 1);
        }
        else
            ft_putchar_fd(*format, 1);
        format++;
    }
    va_end(args);
    return (0);
}