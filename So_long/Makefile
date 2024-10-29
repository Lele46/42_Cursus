# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espinell <espinell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 13:23:53 by espinell          #+#    #+#              #
#    Updated: 2024/04/12 13:24:17 by espinell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_NAME = so_long_bonus

SRCS = ./mandatory/so_long.c ./mandatory/so_long_utils.c ./mandatory/player_moves.c ./mandatory/get_next_line.c ./mandatory/get_next_line_utils.c \
	./mandatory/get_map.c ./mandatory/get_map_utils.c ./mandatory/get_map_utils2.c ./mandatory/get_inputs.c

BSRCS = ./bonus/so_long_bonus.c ./bonus/so_long_utils_bonus.c ./bonus/player_moves_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c \
	./bonus/get_map_bonus.c ./bonus/get_map_utils_bonus.c ./bonus/get_map_utils2_bonus.c ./bonus/get_inputs_bonus.c ./bonus/animations_bonus.c  \
	./bonus/init_images_bonus.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

MLX = "https://github.com/42Paris/minilibx-linux.git"

MLX_DIR = minilibx-linux

FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext

%.o: %.c
	cc -Wall -Wextra -Werror -g -c $< -o $@

all: $(MLX_DIR) $(NAME)

bonus: $(MLX_DIR) $(BONUS_NAME)

$(MLX_DIR):
	@git clone $(MLX)
	@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -g $(OBJS) $(FLAGS) -o $(NAME)

$(BONUS_NAME): $(BOBJS)
	cc -Wall -Wextra -Werror -g $(BOBJS) $(FLAGS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	
re: fclean all
