# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 14:40:05 by aaitelka          #+#    #+#              #
#    Updated: 2023/11/17 14:40:15 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
HEAD	:=	include/libftprintf.h
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
AR		:=	ar rcs
RM		:=	rm -f

SRCS	:=	ft_printf.c src/put_nbr.c src/put_char.c src/put_str.c src/put_hex.c

OBJS	:=	$(SRCS:%c=%o)

all		:	 $(NAME)

%o		:	%c $(HEAD)
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)	:	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all