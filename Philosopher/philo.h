/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:55:23 by espinell          #+#    #+#             */
/*   Updated: 2024/06/28 10:48:51 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_rules;

typedef struct s_philosopher
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*rules;
	pthread_t			thread_id;
}						t_philosopher;

typedef struct s_rules
{
	int					nb_philo;
	int					nb_eat;
	int					dead;
	int					all_ate;
	long long			time_death;
	long long			time_eat;
	long long			time_sleep;
	long long			first_timestamp;
	long long			start_time;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		ate_check;
	pthread_mutex_t		forks[200];
	pthread_mutex_t		writing;
	t_philosopher		philosophers[200];
}						t_rules;

long long	ft_atoll(char *str);
long long	get_time(void);
int			mutex_init(t_rules *r);
int			init_routine(t_rules *r);
int			init(int argc, char **argv, t_rules *r);
void		*routine(void *v_r);
void		ft_dead(t_rules *r);
void		init_philo(t_rules *r);
void		ft_print(t_rules *r, int i, char *str, long long time);
void		ft_dead_check(t_rules *r);

#endif