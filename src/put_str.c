/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:26:22 by aaitelka          #+#    #+#             */
/*   Updated: 2023/11/26 21:58:22 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	put_str(char *s)
{
	int	counter;

	counter = 0;
	if (!s)
		return (put_str("(null)"));
	while (*s)
		counter += put_char(*s++);
	return (counter);
}
