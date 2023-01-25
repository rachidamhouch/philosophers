/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:04:04 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/21 18:04:19 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_usec / 1000 + t.tv_sec * 1000);
}

void	ft_sleep(unsigned int dur)
{
	unsigned int	start;

	start = get_time();
	while (get_time() - start < dur)
		usleep(10);
}

void	ft_kill(t_philos philos)
{
	int	i;

	i = 0;
	while (i < philos.num_of_philo)
		kill(philos.pid[i++], SIGINT);
}
