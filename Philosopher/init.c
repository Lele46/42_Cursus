/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:42:21 by espinell          #+#    #+#             */
/*   Updated: 2024/06/28 17:15:48 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_rules *r)
{
	int	i;

	i = 0;
	while (i < r->nb_philo)
	{
		r->philosophers[i].id = i + 1;
		r->philosophers[i].x_ate = 0;
		r->philosophers[i].left_fork_id = i;
		r->philosophers[i].right_fork_id = (i + 1) % r->nb_philo;
		r->philosophers[i].t_last_meal = 0;
		r->philosophers[i].rules = r;
		i++;
	}
}

int	init_routine(t_rules *r)
{
	int	i;

	i = r->nb_philo;
	while (--i >= 0)
	{
		if (pthread_create(&r->philosophers[i].thread_id, NULL, routine,
				&r->philosophers[i]))
			return (1);
		pthread_mutex_lock(&r->meal_check);
		r->philosophers[i].t_last_meal = get_time();
		pthread_mutex_unlock(&r->meal_check);
	}
	ft_dead(r);
	i = r->nb_philo;
	while (--i >= 0)
		pthread_join(r->philosophers[i].thread_id, NULL);
	i = r->nb_philo;
	while (--i >= 0)
		pthread_mutex_destroy(&r->forks[i]);
	pthread_mutex_destroy(&r->meal_check);
	pthread_mutex_destroy(&r->writing);
	pthread_mutex_destroy(&r->ate_check);
	return (0);
}

int	mutex_init(t_rules *r)
{
	int	i;

	i = 0;
	while (i <= r->nb_philo)
	{
		if (pthread_mutex_init(&r->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&r->meal_check, NULL))
		return (1);
	if (pthread_mutex_init(&r->writing, NULL))
		return (1);
	if (pthread_mutex_init(&r->ate_check, NULL))
		return (1);
	return (0);
}

int	init(int argc, char **argv, t_rules *r)
{
	r->nb_philo = ft_atoll(argv[1]);
	r->time_death = ft_atoll(argv[2]);
	r->time_eat = ft_atoll(argv[3]);
	r->time_sleep = ft_atoll(argv[4]);
	r->dead = 0;
	r->all_ate = 0;
	if (r->nb_philo < 1 || r->nb_philo > 200 || r->time_death <= 0
		|| r->time_eat <= 0 || r->time_sleep <= 0)
		return (1);
	if (argc == 6)
	{
		r->nb_eat = ft_atoll(argv[5]);
		if (r->nb_eat <= 0)
			return (1);
	}
	else
		r->nb_eat = -1;
	if (mutex_init(r) == 1)
		return (1);
	r->start_time = get_time();
	init_philo(r);
	return (0);
}
