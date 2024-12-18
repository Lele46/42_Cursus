# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espinell <espinell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 10:37:43 by espinell          #+#    #+#              #
#    Updated: 2024/10/31 10:37:43 by espinell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ClapTrap.cpp ScavTrap.cpp main.cpp
NAME = ScavTrap
CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all