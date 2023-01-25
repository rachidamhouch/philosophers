/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:03:14 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/23 23:01:55 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+')
			return (printf("Invalid Arguments\n"));
		i++;
	}
	return (0);
}

int	check_errors(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (printf("Arguments number is incorrect!\n"));
	while (i < ac)
	{
		if (is_num(av[i]))
			return (1);
			i++;
	}
	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 1)
			return (printf("Invalid Arguments\n"));
			i++;
	}
	return (0);
}

void	init_philo(int ac, char **av, t_philos *philo, t_args *args)
{
	int			i;

	i = 0;
	if (ac == 6)
		args->num_must_eat = ft_atoi(av[5]);
	args->time_to_die = (unsigned int)ft_atoi(av[2]);
	args->num_of_arg = ac;
	args->num_of_philo = ft_atoi(av[1]);
	args->time_to_eat = (unsigned int)ft_atoi(av[3]);
	args->time_to_sleep = (unsigned int)ft_atoi(av[4]);
	args->forks = (pthread_mutex_t *)malloc(args->num_of_philo
			* sizeof(pthread_mutex_t));
	args->start = 1;
	args->stop = 1;
	pthread_mutex_init(&args->print, NULL);
	while (i < ft_atoi(av[1]))
	{
		philo[i].num_of_eat = 0;
		philo[i].id = i + 1;
		philo[i].last_eat = get_time();
		pthread_mutex_init(&args->forks[i], NULL);
		philo[i].args = args;
		philo[i].done = 0;
		i++;
	}
}

void	crerat_philos(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].args->num_of_philo)
	{
		if (pthread_create(&philos[i].philo, NULL, &routine,
				&philos[i]))
			printf("Failed to create thread!\n");
		usleep(100);
		pthread_detach(philos[i].philo);
		i++;
	}
}
