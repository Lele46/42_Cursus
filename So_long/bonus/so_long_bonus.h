/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:30:51 by espinell          #+#    #+#             */
/*   Updated: 2024/01/31 14:55:33 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define SIZE 64
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_entities
{
	int	player;
	int	exit;
	int	collectible;
	int	enemy;
	int	i;
	int	j;
}	t_entities;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*textures[14];
	char	**map;
	t_coord	player;
	t_coord	exit;
	int		col;
	int		moves;
}	t_game;

int		check_wall(char **map, int height);
int		check_entities(char **map);
char	**get_map(char *argv, t_game *game);
void	ft_error(char *str, int num);
void	img_error(t_game *game, int index, char *str, int num);
void	*ft_calloc(size_t count, size_t size);
int		ft_check_file(char *file);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlenh(const char *s);
int		get_height(char *argv);
void	free_matrix(char **tmp_map);
int		free_and_destroy(t_game *game);
void	free_map(char **map, t_game *game);
int		get_inputs(int keycode, t_game *game);
char	*ft_itoa(int num);
void	ft_printmoves(t_game *game);
void	get_map_size(char **map, t_coord mapsize);
int		get_player_coordinate(char **map, int flag);
char	**copy_matrix(char **map);
void	ft_victory(t_game *game);
void	ft_printmoves(t_game *game);
void	init_images(t_game *game);
int		animation(t_game *game);
void	find_collectible(t_game *game, int i);
void	find_trap(t_game *game, int i);

// GNL

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

// Player moves

void	player_move_up(t_game *game);
void	player_move_down(t_game *game);
void	player_move_left(t_game *game);
void	player_move_right(t_game *game);

#endif