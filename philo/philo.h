/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:16:06 by ramhouch          #+#    #+#             */
/*   Updated: 2023/01/21 14:30:58 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct args
{
	unsigned int		time_to_die;
	int					num_must_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	int					num_of_arg;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		curr_time;
	int					num_of_philo;
	int					start;
	int					stop;
}t_args;

typedef struct philos
{
	pthread_t		philo;
	unsigned int	last_eat;
	int				num_of_eat;
	int				id;
	t_args			*args;
	int				done;
}t_philos;

int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					check_errors(int ac, char **av);
void				init_philo(int ac, char **av,
						t_philos *philo, t_args *args);
void				*routine(void *arg);
void				crerat_philos(t_philos *philos);
unsigned int		get_time(void);
void				ft_sleep(unsigned int dur);
int					die(t_philos *philos);

#endif
