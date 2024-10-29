/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:53:32 by espinell          #+#    #+#             */
/*   Updated: 2024/03/18 14:30:58 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all(char **cmd, char **path, char *valid_cmd, int flag)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	if (flag == 1)
		free(valid_cmd);
}

int	ft_refork(int *fd, char **argv, char **envp, pid_t *pid2)
{
	*pid2 = fork();
	if (*pid2 == -1)
		return (ft_error("Error: fork failed", 3));
	if (*pid2 == 0)
		second_cmd(fd, argv, envp);
	return (0);
}

void	arg_contr(int argc)
{
	if (argc != 5)
		ft_error("Error: wrong number of arguments", 1);
}
