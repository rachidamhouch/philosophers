/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:19:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/21 18:02:40 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philos	philos;
	int			s;
	sem_t		*print;

	if (check_errors(ac, av))
		return (1);
	init_philo(ac, av, &philos);
	print = sem_open("print", O_CREAT | O_EXCL, 0664, 1);
	if (!crerat_philos(&philos))
		routine(philos, print);
	else
	{
		while (waitpid(-1, &s, 0) != -1)
		{
			if (s)
			{
				ft_kill(philos);
				break ;
			}
		}
		sem_close(philos.sem);
		sem_close(print);
	}
	return (0);
}
