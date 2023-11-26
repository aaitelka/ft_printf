/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:01:51 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/26 15:59:12 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int     ft_printf(const char *format, ...);

void    put_hex(unsigned long decimal, int base, char c);

void	put_nbr(long nbr, int fd);

void	put_char(unsigned char c, int fd);

void	put_str(char *s, int fd);

#endif
