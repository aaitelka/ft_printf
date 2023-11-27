/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:01:51 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/26 21:56:05 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		put_str(char *s);

int		put_nbr(long nbr);

int		put_char(char c);

int		put_hex(unsigned long decimal, char placeholder);
#endif
