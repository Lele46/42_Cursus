# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espinell <espinell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 11:53:17 by espinell          #+#    #+#              #
#    Updated: 2024/03/18 13:47:24 by espinell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c pipex_utils.c ft_split.c ft_free_all.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	cc -g -Wall -Wextra -Werror $(OBJS) -o $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -g -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.Phony: clean fclean re
