# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espinell <espinell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 10:38:22 by espinell          #+#    #+#              #
#    Updated: 2024/10/31 10:38:22 by espinell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ClapTrap.cpp FragTrap.cpp main.cpp
NAME = FragTrap
CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all