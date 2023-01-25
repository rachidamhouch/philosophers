/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:21:10 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/21 18:42:57 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die(t_philos *philos)
{
	int				i;
	unsigned int	last;

	i = 0;
	while (i < philos[0].args->num_of_philo)
	{
		last = philos[i].last_eat;
		if (get_time() - last > philos[0].args->time_to_die)
		{
			philos[0].args->stop = 0;
			pthread_mutex_lock(&philos[0].args->print);
			if (!philos[i].done)
				printf("%ums: Philosopher %d died\n", get_time()
					- philos[0].args->curr_time, philos[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}
