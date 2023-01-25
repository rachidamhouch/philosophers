/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:12:03 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/21 18:42:20 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_msg(sem_t *print, int id, unsigned int time, char *msg)
{
	sem_wait(print);
	printf("%ums: Philosopher %d %s\n",
		get_time() - time, id, msg);
	sem_post(print);
}

static void	check(t_philos philo, sem_t *print)
{
	unsigned int	last;

	if (philo.num_of_eat == philo.num_must_eat && philo.num_of_arg == 6)
		exit(0);
	last = philo.last_eat;
	if (get_time() - philo.last_eat > philo.time_to_die)
	{
		sem_wait(print);
		printf("%ums: Philosopher %d died\n", get_time()
			- philo.curr_time, philo.id);
		exit(1);
	}
}

void	routine(t_philos philo, sem_t *print)
{
	while (1)
	{
		sem_wait(philo.sem);
		check(philo, print);
		print_msg(print, philo.id, philo.curr_time, "has taken a fork");
		if (philo.num_of_philo == 1)
		{
			ft_sleep(philo.time_to_die);
			printf("%ums: Philosopher %d died\n", philo.time_to_die, philo.id);
			exit(1);
		}
		sem_wait(philo.sem);
		check(philo, print);
		print_msg(print, philo.id, philo.curr_time, "has taken a fork");
		philo.last_eat = get_time();
		philo.num_of_eat++;
		print_msg(print, philo.id, philo.curr_time, "is eating");
		ft_sleep(philo.time_to_eat);
		sem_post(philo.sem);
		sem_post(philo.sem);
		check(philo, print);
		print_msg(print, philo.id, philo.curr_time, "is sleeping");
		ft_sleep(philo.time_to_sleep);
		print_msg(print, philo.id, philo.curr_time, "is thinking");
	}
}
