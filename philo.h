/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:05:41 by lsabik            #+#    #+#             */
/*   Updated: 2023/04/07 17:42:23 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdlib.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <unistd.h>

# define SUCCESS 1
# define FAILURE 0
# define EAT 1
# define SLEEP 2

typedef struct s_philosopher	t_philosopher;

typedef struct s_data
{
	long						nb_of_philosopher;
	long						time_to_die;
	long						time_to_eat;
	long						time_to_sleep;
	long						nb_of_meals;
	int							dead;
	int							eat;
	long						start_time;
	pthread_mutex_t				print;
	pthread_mutex_t				eating;
	pthread_mutex_t				last_meal;
	pthread_mutex_t				*forks;
	t_philosopher				*philo;
}								t_data;

typedef struct s_philosopher
{
	int							fork_id;
	int							left_fork;
	int							right_fork;
	long						t_last_meal;
	pthread_t					thread;
	t_data						*data;
}								t_philosopher;

int								init(t_data *data, char **av);
void							*philo_action(void *argv);
int								print_error(char *str);
long							get_time(void);
long							ft_atoi(char *str);
void							print_out(t_philosopher *philo, char *str);
void							*ft_calloc(size_t count, size_t size);
int								join_free(t_data *data, t_philosopher *philo);
void							my_sleep(long long time);

#endif
