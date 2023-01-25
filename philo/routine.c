/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:12:03 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/21 14:22:35 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_msg(t_philos *philo, char *msg)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ums: Philosopher %d %s\n",
		get_time() - philo->args->curr_time, philo->id, msg);
	pthread_mutex_unlock(&philo->args->print);
}

static int	take_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->args->forks[philo->id - 1]);
	if (philo[0].args->start)
	{
		philo[0].args->curr_time = get_time();
		philo[0].args->start = 0;
	}
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->args->forks
	[philo->id % philo->args->num_of_philo]);
	print_msg(philo, "has taken a fork");
	philo->last_eat = get_time();
	print_msg(philo, "is eating");
	ft_sleep(philo->args->time_to_eat);
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->args->forks
	[philo->id % philo->args->num_of_philo]);
	pthread_mutex_unlock(&philo->args->forks[philo->id - 1]);
	return (philo->args->num_of_arg == 6
		&& philo->num_of_eat == philo->args->num_must_eat);
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (philo->args->stop)
	{
		if (take_fork(philo))
		{
			philo->done = 1;
			return (0);
		}
		print_msg(philo, "is sleeping");
		ft_sleep(philo->args->time_to_sleep);
		print_msg(philo, "is thinking");
	}
	return (0);
}
