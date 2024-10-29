/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:29:48 by lbarlett          #+#    #+#             */
/*   Updated: 2024/10/02 12:27:18 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	str_check(char c)
{
	if ((c >= '0' || c <= '9') && c != ',' && c != ' ' && c != '\t')
		return (1);
	return (0);
}

static int	skip_tabs(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == '\t')
			i += 4;
		else
			i++;
		j++;
	}
	return (i);
}

char	*my_strdup(const char *s)
{
	char	*str;
	t_index	id;

	id.k = 0;
	id.i = skip_tabs(s);
	str = (char *)malloc(sizeof(char) * (id.i + 1));
	if (!str)
		return (NULL);
	id.j = -1;
	while (s[++id.j])
	{
		if (s[id.j] == '\t')
		{
			id.i = 0;
			while (id.i < 4)
			{
				str[id.k++] = ' ';
				id.i++;
			}
		}
		else
			str[id.k++] = s[id.j];
	}
	str[id.k] = '\0';
	return (str);
}

int	comma_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == ','
			|| str[i] == '\r')
			i++;
		if (str[i] >= '0' || str[i] <= '9')
		{
			count++;
			i++;
			while (str[i] && str_check(str[i]))
				i++;
			if (count > 3)
			{
				printf("Invalid color code\n");
				return (0);
			}
		}
		i++;
	}
	return (count);
}

int	valid_color(char *line)
{
	int	j;
	int	color;

	j = skip_space(line);
	if (line[j] == '\0')
		return (-1);
	else
	{
		color = set_color(line);
		if (color == -1)
			return (-1);
		return (color);
	}
	return (-1);
}
