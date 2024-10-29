# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espinell <espinell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 10:44:53 by espinell          #+#    #+#              #
#    Updated: 2024/05/24 14:15:07 by espinell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = init.c philo_utils.c philo.c

NAME = philo

COMPILE = gcc -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

%.o: %.c
	cc -Wall -Wextra -Werror -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) -g $(OBJS) -lpthread -o $(NAME) 

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
