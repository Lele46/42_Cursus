/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:30:31 by espinell          #+#    #+#             */
/*   Updated: 2024/02/03 10:37:01 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_basics(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[0], j * SIZE, i * SIZE);
		game->player.x = j;
		game->player.y = i;
	}
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[5], j * SIZE, i * SIZE);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[6], j * SIZE, i * SIZE);
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[9], j * SIZE, i * SIZE);
		game->col++;
	}
}

static void	load_images(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			load_basics(game, i, j);
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures[7], j * SIZE, i * SIZE);
				game->exit.x = j;
				game->exit.y = i;
			}
			if (game->map[i][j] == 'N')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures[11], j * SIZE, i * SIZE);
		}
	}
}

static void	init_env(t_game *game, int size)
{
	game->textures[5] = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&size, &size);
	if (game->textures[5] == NULL)
		img_error(game, 5, "Error: invalid texture\n", 6);
	game->textures[6] = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&size, &size);
	if (game->textures[6] == NULL)
		img_error(game, 6, "Error: invalid texture\n", 6);
	game->textures[7] = mlx_xpm_file_to_image(game->mlx, "./textures/exitc.xpm",
			&size, &size);
	if (game->textures[7] == NULL)
		img_error(game, 7, "Error: invalid texture\n", 6);
	game->textures[8] = mlx_xpm_file_to_image(game->mlx, "./textures/exito.xpm",
			&size, &size);
	if (game->textures[8] == NULL)
		img_error(game, 8, "Error: invalid texture\n", 6);
	game->textures[9] = mlx_xpm_file_to_image(game->mlx, "./textures/key1.xpm",
			&size, &size);
	if (game->textures[9] == NULL)
		img_error(game, 9, "Error: invalid texture\n", 6);
	game->textures[10] = mlx_xpm_file_to_image(game->mlx, "./textures/key2.xpm",
			&size, &size);
	if (game->textures[10] == NULL)
		img_error(game, 10, "Error: invalid texture\n", 6);
}

static void	init_protag(t_game *game, int size)
{
	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "./textures/PG1.xpm",
			&size, &size);
	if (game->textures[0] == NULL)
		img_error(game, 0, "Error: invalid texture\n", 6);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "./textures/PG2.xpm",
			&size, &size);
	if (game->textures[1] == NULL)
		img_error(game, 1, "Error: invalid texture\n", 6);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "./textures/PG3.xpm",
			&size, &size);
	if (game->textures[2] == NULL)
		img_error(game, 2, "Error: invalid texture\n", 6);
	game->textures[3] = mlx_xpm_file_to_image(game->mlx, "./textures/PG4.xpm",
			&size, &size);
	if (game->textures[3] == NULL)
		img_error(game, 3, "Error: invalid texture\n", 6);
	game->textures[4] = mlx_xpm_file_to_image(game->mlx, "./textures/PG5.xpm",
			&size, &size);
	if (game->textures[4] == NULL)
		img_error(game, 4, "Error: invalid texture\n", 6);
}

void	init_images(t_game *game)
{
	int	size;

	size = SIZE;
	init_protag(game, size);
	init_env(game, size);
	game->textures[11] = mlx_xpm_file_to_image(game->mlx, "./textures/tr1.xpm",
			&size, &size);
	if (game->textures[11] == NULL)
		img_error(game, 11, "Error: invalid texture\n", 6);
	game->textures[12] = mlx_xpm_file_to_image(game->mlx, "./textures/tr2.xpm",
			&size, &size);
	if (game->textures[12] == NULL)
		img_error(game, 12, "Error: invalid texture\n", 6);
	game->textures[13] = mlx_xpm_file_to_image(game->mlx, "./textures/tr3.xpm",
			&size, &size);
	if (game->textures[13] == NULL)
		img_error(game, 13, "Error: invalid texture\n", 6);
	load_images(game);
}