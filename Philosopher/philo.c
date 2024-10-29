/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:41:51 by espinell          #+#    #+#             */
/*   Updated: 2024/06/28 17:11:53 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philosopher *philo)
{
	t_rules	*r;

	r = philo->rules;
	ft_print(r, philo->id, "is sleeping", get_time() - r->start_time);
	usleep(r->time_sleep * 1000);
}

void	think(t_philosopher *philo)
{
	t_rules	*r;

	r = philo->rules;
	ft_print(r, philo->id, "is thinking", get_time() - r->start_time);
}

void	eat(t_philosopher *philo)
{
	t_rules	*r;

	r = philo->rules;
	pthread_mutex_lock(&r->forks[philo->left_fork_id]);
	ft_print(r, philo->id, "has taken a fork", get_time() - r->start_time);
	if (r->nb_philo == 1)
	{
		usleep(r->time_death * 1000);
		pthread_mutex_unlock(&r->forks[philo->left_fork_id]);
		return ;
	}
	pthread_mutex_lock(&r->forks[philo->right_fork_id]);
	ft_print(r, philo->id, "has taken a fork", get_time() - r->start_time);
	ft_print(r, philo->id, "is eating", get_time() - r->start_time);
	usleep(r->time_eat * 1000);
	pthread_mutex_lock(&r->meal_check);
	philo->t_last_meal = get_time();
	pthread_mutex_unlock(&r->meal_check);
	pthread_mutex_lock(&r->ate_check);
	philo->x_ate++;
	pthread_mutex_unlock(&r->ate_check);
	pthread_mutex_unlock(&r->forks[philo->right_fork_id]);
	pthread_mutex_unlock(&r->forks[philo->left_fork_id]);
}

void	*routine(void *v_r)
{
	t_philosopher	*r;

	r = (t_philosopher *) v_r;
	if (r->id % 2 == 0)
		usleep(15000);
	while (r->x_ate != r->rules->nb_eat)
	{
		pthread_mutex_lock(&r->rules->writing);
		if (r->rules->dead == 1)
		{
			pthread_mutex_unlock(&r->rules->writing);
			return (NULL);
		}
		pthread_mutex_unlock(&r->rules->writing);
		eat(r);
		if (r->x_ate == r->rules->nb_eat)
			return (NULL);
		ft_sleep(r);
		think(r);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
		return (1);
	if (init(argc, argv, &rules) == 1)
	{
		write(1, "Error: Invalid arguments\n", 26);
		return (1);
	}
	if (init_routine(&rules))
		return (1);
}
