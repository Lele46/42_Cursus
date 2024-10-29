/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .get_next_line_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:36 by espinell          #+#    #+#             */
/*   Updated: 2023/11/18 15:50:13 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	char			*t;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	t = (char *) s;
	while (t[i] != '\0')
	{
		if ((unsigned char)c == t[i])
		{
			return (t + i);
		}
		i++;
	}
	if (t[i] == (unsigned char) c)
		return (t + i);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		x;
	char	*str;

	x = 0;
	str = (char *)malloc(sizeof (char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[x])
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	j;
	size_t	z;
	size_t	i;
	char	*fstr;

	x = ft_strlen(s1);
	j = ft_strlen(s2);
	z = -1;
	fstr = (char *)malloc(sizeof (char) * (x + j + 1));
	if (!fstr)
		return (NULL);
	while (s1[++z])
		fstr[z] = s1[z];
	i = z;
	z = -1;
	while (s2[++z])
		fstr[i + z] = s2[z];
	fstr[i + z] = '\0';
	return (fstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	size_t	x;
	char	*str;

	x = 0;
	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (start > size_s)
		start = size_s;
	if (len > (size_s - start))
		len = (size_s - start);
	if (start == size_s)
		str = (char *)malloc(sizeof(char));
	else
		str = (char *)malloc((sizeof(char) * len) + 1);
	if (!str)
		return (NULL);
	while (x < len && s[start] && start < size_s)
		str[x++] = s[start++];
	str[x] = '\0';
	return (str);
}