# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espinell <espinell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 11:03:16 by espinell          #+#    #+#              #
#    Updated: 2024/01/31 11:03:20 by espinell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = algorithm_utils.c algorithm.c int_utils.c lst_utils.c push_swap.c push.c rev_rotate.c rotate.c split.c swap.c utils.c utils2.c
OBJS = $(SRCS:.c=.o)
INCLUDES = .
HEADERS = push_swap.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo compiled $(NAME)

%.o: %.c $(HEADERS)
				@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@echo removed object files

fclean: clean
				@$(RM) $(NAME)
				@echo removed $(NAME)

re: fclean all

.PHONY: all clean fclean re
