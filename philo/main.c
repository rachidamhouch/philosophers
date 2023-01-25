/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:19:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/21 14:45:32 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philos	*philos;
	t_args		args;
	int			i;

	i = 0;
	if (check_errors(ac, av))
		return (1);
	philos = (t_philos *)malloc(sizeof(t_philos) * ft_atoi(av[1]));
	init_philo(ac, av, philos, &args);
	crerat_philos(philos);
	while (1)
	{
		if (die(philos))
			break ;
	}
	pthread_mutex_destroy(&args.print);
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_destroy(&args.forks[i]);
		i++;
	}
	return (0);
}
