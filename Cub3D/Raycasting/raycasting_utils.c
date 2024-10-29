/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:38:38 by espinell          #+#    #+#             */
/*   Updated: 2024/10/02 10:38:38 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_angle(t_game *game)
{
	if (game->ray->angle < 0)
		game->ray->angle += 2 * PI;
	if (game->ray->angle > 2 * PI)
		game->ray->angle -= 2 * PI;
}

void	ray_increment_v(t_game *game, int map_width, int map_height)
{
	if (game->ray->map_x >= 0 && game->ray->map_x < map_width
		&& game->ray->map_y >= 0
		&& game->ray->map_y < map_height
		&& game->map[game->ray->map_y][game->ray->map_x] == '1')
		game->ray->dof = 64;
	else
	{
		game->ray->v_x += game->ray->v_x_off;
		game->ray->v_y += game->ray->v_y_off;
		game->ray->dof += 1;
	}
}

void	ray_increment_h(t_game *game, int map_width, int map_height)
{
	if (game->ray->map_x >= 0 && game->ray->map_x < map_width
		&& game->ray->map_y >= 0
		&& game->ray->map_y < map_height
		&& game->map[game->ray->map_y][game->ray->map_x] == '1')
		game->ray->dof = 64;
	else
	{
		game->ray->h_x += game->ray->h_x_off;
		game->ray->h_y += game->ray->h_y_off;
		game->ray->dof += 1;
	}
}

void	check_pi_v(t_game *game)
{
	if (game->ray->angle > P2 && game->ray->angle < P3)
	{
		game->ray->v_x = (((int)game->player->x / (TILE_SIZE / 2))
				* (TILE_SIZE / 2)) - 0.0001;
		game->ray->v_y = (game->player->x - game->ray->v_x)
			* game->ray->ntan + game->player->y;
		game->ray->v_x_off = -(TILE_SIZE / 2);
		game->ray->v_y_off = -game->ray->v_x_off * game->ray->ntan;
	}
	if (game->ray->angle < P2 || game->ray->angle > P3)
	{
		game->ray->v_x = (((int)game->player->x / (TILE_SIZE / 2))
				* (TILE_SIZE / 2)) + (TILE_SIZE / 2);
		game->ray->v_y = (game->player->x - game->ray->v_x)
			* game->ray->ntan + game->player->y;
		game->ray->v_x_off = (TILE_SIZE / 2);
		game->ray->v_y_off = -game->ray->v_x_off * game->ray->ntan;
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->v_x = game->player->x;
		game->ray->v_y = game->player->y;
		game->ray->dof = 64;
	}
}

void	check_pi_h(t_game *game)
{
	if (game->ray->angle > PI)
	{
		game->ray->h_y = (((int)game->player->y / (TILE_SIZE / 2))
				* (TILE_SIZE / 2)) - 0.0001;
		game->ray->h_x = (game->player->y - game->ray->h_y)
			* game->ray->atan + game->player->x;
		game->ray->h_y_off = -(TILE_SIZE / 2);
		game->ray->h_x_off = -game->ray->h_y_off * game->ray->atan;
	}
	if (game->ray->angle < PI)
	{
		game->ray->h_y = (((int)game->player->y / (TILE_SIZE / 2))
				* (TILE_SIZE / 2)) + (TILE_SIZE / 2);
		game->ray->h_x = (game->player->y - game->ray->h_y)
			* game->ray->atan + game->player->x;
		game->ray->h_y_off = (TILE_SIZE / 2);
		game->ray->h_x_off = -game->ray->h_y_off * game->ray->atan;
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->h_x = game->player->x;
		game->ray->h_y = game->player->y;
		game->ray->dof = 64;
	}
}
