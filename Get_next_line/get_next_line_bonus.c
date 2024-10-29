/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .get_next_line_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:11:51 by espinell          #+#    #+#             */
/*   Updated: 2023/11/18 15:50:20 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include "get_next_line_utils.c"
//#include <fcntl.h>

static char	*read_line(int fd, char *buf, char *backup)
{
	char	*tmp;
	int		check;

	check = 1;
	while (check)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (0);
		if (check == 0)
			break ;
		buf[check] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *backup)
{
	char	*line;
	int		start;
	int		i;

	i = -1;
	start = 0;
	if (!backup)
		return (NULL);
	while (backup[start] != '\0' && backup[start] != '\n')
		start++;
	line = (char *)malloc(sizeof(char) * start + 1 + (backup[start] == '\n'));
	if (!line)
		return (NULL);
	while (backup[++i] != '\n' && backup[i] != '\0')
		line[i] = backup[i];
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*free_backup(char *backup)
{
	int		size;
	int		start;
	char	*tmp;

	start = 0;
	size = 0;
	if (!backup || backup[0] == '\0')
		return (NULL);
	while (backup[start] != '\0' && backup[start] != '\n')
		start++;
	if (backup[start] == '\0' || backup[start + 1] == '\0')
	{
		free(backup);
		return (NULL);
	}
	while (backup[size] != '\0')
		size++;
	size -= start;
	tmp = backup;
	backup = ft_substr(tmp, start + 1, size);
	free (tmp);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (backup[fd])
		{
			free(backup[fd]);
			backup[fd] = NULL;
		}
		return (NULL);
	}
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (ft_strchr(backup[fd], '\n') == NULL)
		backup[fd] = read_line(fd, buf, backup[fd]);
	free(buf);
	buf = NULL;
	line = extract(backup[fd]);
	if (!line)
		return (NULL);
	backup[fd] = free_backup(backup[fd]);
	return (line);
}
