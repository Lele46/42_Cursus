/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:56:33 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:56:33 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	compare_elements(char *str, char *str1, char *str2)
{
	if (ft_strncmp(str, str1, ft_strlen(str1)) == 0
		|| ft_strncmp(str, str2, ft_strlen(str2)) == 0)
		return (1);
	return (0);
}

void	load_textures(t_game *game, char *path, int dir)
{
	game->texture[dir].ptr = mlx_xpm_file_to_image(game->mlx,
			path, &game->texture[dir].width,
			&game->texture[dir].height);
	if (game->texture[dir].ptr == NULL)
	{
		printf("Error: texture not found\n");
		free(path);
		free_and_destroy(game);
	}
	game->texture[dir].data = mlx_get_data_addr(game->texture[dir].ptr,
			&game->texture[dir].bpp,
			&game->texture[dir].len, &game->texture[dir].endian);
}

void	set_image(char *str, t_game *game, int dir)
{
	int		i;
	char	*path;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t'
		&& str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
		i++;
	path = ft_substr(str, 0, i);
	i = 0;
	while (path[++i])
	{
		if (path[i] == '.')
		{
			if (ft_strncmp(path + i, ".xpm", 4) != 0)
			{
				free(path);
				free_and_destroy(game);
			}
		}
	}
	mlx_destroy_image(game->mlx, game->texture[dir].ptr);
	load_textures(game, path, dir);
	free(path);
}

static int	check_rgb(char **rgb_s)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (ft_atoi(rgb_s[i]) < 0 || ft_atoi(rgb_s[i]) > 255)
		{
			printf("Invalid color code\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	set_color(char *str)
{
	int		i;
	int		color;
	char	**rgb_s;
	char	*tmp;

	if (comma_count(str) == 0)
		return (-1);
	rgb_s = ft_split(str, ',');
	i = -1;
	while (rgb_s[++i])
	{
		tmp = ft_strtrim(rgb_s[i], "\n");
		free(rgb_s[i]);
		rgb_s[i] = ft_strtrim(tmp, "\r");
		free(tmp);
	}
	if (check_rgb(rgb_s) == -1)
	{
		free_matrix(rgb_s);
		return (-1);
	}
	color = create_trgb(0, (unsigned char)ft_atoi(rgb_s[0]),
			(unsigned char)ft_atoi(rgb_s[1]), (unsigned char)ft_atoi(rgb_s[2]));
	free_matrix(rgb_s);
	return (color);
}
