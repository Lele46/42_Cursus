/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:29:41 by espinell          #+#    #+#             */
/*   Updated: 2024/01/31 14:29:44 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	delayanim(void)
{
	int	c;
	int	d;

	c = 1;
	while (c <= 10000)
	{
		d = 1;
		while (d <= 10000)
			d++;
		c++;
	}
}

static void	protag_anim(t_game *game)
{
	static int	i = -1;

	if (++i == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	else if (i == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[1], game->player.x * SIZE, game->player.y * SIZE);
	else if (i == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[2], game->player.x * SIZE, game->player.y * SIZE);
	else if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[3], game->player.x * SIZE, game->player.y * SIZE);
	else
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[4], game->player.x * SIZE, game->player.y * SIZE);
		i = -1;
	}
}

static void	collect_anim(t_game *game)
{
	static int	j = -1;

	if (++j == 0)
		find_collectible(game, 0);
	else if (j == 1)
	{
		find_collectible(game, 1);
		j = -1;
	}
}

static void	trap_anim(t_game *game)
{
	static int	k = -1;

	if (++k == 0)
		find_trap(game, 0);
	else if (k == 1)
		find_trap(game, 1);
	else if (k == 2)
	{
		find_trap(game, 2);
		k = -1;
	}
}

int	animation(t_game *game)
{
	delayanim();
	protag_anim(game);
	collect_anim(game);
	trap_anim(game);
	return (0);
}
