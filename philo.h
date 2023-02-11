
#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct	s_philosopher
{
	int					fork_id;
	int					left_fork;
	int					right_fork;
} 				t_philosopher;

typedef struct	s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	pthread			thread;
	pthread_mutex	*forks;
	t_philosopher	*philo;
}				t_data;
