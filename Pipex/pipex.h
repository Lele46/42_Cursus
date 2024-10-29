/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:53:00 by espinell          #+#    #+#             */
/*   Updated: 2024/03/18 14:29:30 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

int		ft_error(char *str, int exit_code);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	ft_free_all(char **cmd, char **path, char *valid_cmd, int flag);
void	second_cmd(int *fd, char **argv, char **envp);
int		ft_refork(int *fd, char **argv, char **envp, pid_t *pid2);
void	arg_contr(int argc);

char	find_quotetype(const char *s, size_t i, char quote);
int		find_unquoted(const char *s, char c, size_t start);
int		find_quoted(const char *s, char quote, size_t start);

#endif