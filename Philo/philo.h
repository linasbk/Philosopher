/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:05:41 by lsabik            #+#    #+#             */
/*   Updated: 2023/02/19 20:21:30 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include"stdlib.h"
# include<unistd.h>
# include<limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

# define SUCCESS 1
# define FAILURE 0

typedef struct s_philosopher
{
	int	fork_id;
	int	left_fork;
	int	right_fork;
	int	t_last_meal;
}				t_philosopher;

typedef struct s_data
{
	int				nb_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	pthread_t		thread;
	pthread_mutex_t	*forks;
	t_philosopher	*philo;
}				t_data;

int		init(t_data *data, char **av);
void	*philo_action(void *argv);
int		print_error(char *str);
long	get_time(void);
long	ft_atoi(char *str);

#endif
