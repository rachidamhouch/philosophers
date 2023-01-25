/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:03:14 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/21 18:02:55 by ramhouch         ###   ########.fr       */
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

void	init_philo(int ac, char **av, t_philos *philos)
{
	int			i;

	i = 0;
	sem_unlink("philosophers");
	sem_unlink("print");
	if (ac == 6)
		philos->num_must_eat = ft_atoi(av[5]);
	philos->time_to_die = (unsigned int)ft_atoi(av[2]);
	philos->num_of_arg = ac;
	philos->num_of_philo = ft_atoi(av[1]);
	philos->time_to_eat = (unsigned int)ft_atoi(av[3]);
	philos->time_to_sleep = (unsigned int)ft_atoi(av[4]);
	philos->num_of_eat = 0;
	philos->last_eat = get_time();
	philos->sem = sem_open("philosophers", O_CREAT,
			0664, philos->num_of_philo);
	philos->curr_time = get_time();
	philos->pid = malloc(philos->num_of_philo * sizeof(int));
}

int	crerat_philos(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philo)
	{
		philos->pid[i] = fork();
		if (!philos->pid[i])
		{
			philos->id = i + 1;
			return (philos->pid[i]);
		}
		i++;
		usleep(50);
	}
	return (1);
}
