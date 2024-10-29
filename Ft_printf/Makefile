# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espinell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 14:55:25 by espinell          #+#    #+#              #
#    Updated: 2023/11/10 15:27:22 by espinell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_itoas.c ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_strlen.c

OBJS = ${SRCS:.c=.o};

all: ${NAME}

${NAME}: ${OBJS}
		ar rcs ${NAME} $?
		ranlib ${NAME}

%.o: %.c
		cc -c -Wall -Wextra -Werror $?

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re 
