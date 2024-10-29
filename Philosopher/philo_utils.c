/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:17:32 by espinell          #+#    #+#             */
/*   Updated: 2024/06/28 11:42:41 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_rules *r, int i, char *str, long long time)
{
	pthread_mutex_lock(&r->writing);
	if (r->dead == 0)
		printf("%lld %d %s\n", time, i, str);
	pthread_mutex_unlock(&r->writing);
}

long long	ft_atoll(char *str)
{
	int			x;
	int			s;
	long long	num;

	num = 0;
	x = 0;
	s = 1;
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			s *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		num *= 10;
		num += str[x] -48;
		x++;
	}
	if ((str[x] < '0' || str[x] > '9') && str[x] != '\0')
		return (-1);
	return (num * s);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_dead(t_rules *r)
{
	int	i;

	while (r->all_ate == 0)
	{
		i = 0;
		while (i < r->nb_philo && r->dead == 0)
		{
			pthread_mutex_lock(&r->meal_check);
			if (get_time() - r->philosophers->t_last_meal >= r->time_death)
				ft_dead_check(r);
			pthread_mutex_unlock(&r->meal_check);
			i++;
		}
		if (r->dead == 1)
			break ;
		i = 0;
		pthread_mutex_lock(&r->ate_check);
		while (r->philosophers[i].x_ate == r->nb_eat && r->nb_eat != -1)
			i++;
		pthread_mutex_unlock(&r->ate_check);
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}

void	ft_dead_check(t_rules *r)
{
	pthread_mutex_lock(&r->writing);
	r->dead = 1;
	pthread_mutex_unlock(&r->writing);
	pthread_mutex_lock(&r->writing);
	printf("%lld %d died\n", get_time() - r->start_time, r->philosophers->id);
	pthread_mutex_unlock(&r->writing);
}
