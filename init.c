#include"philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while(++i < data->number_of_philosophers)
		if (pthread_mutex_init(data->forks[i], NULL))
			return(FAILURE);
	return (SUCCESS);
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philo->fork_id = i;
		pthread_create(&(data->philo[i]->thread), NULL, philo_action, NULL);
	}
}

int init(t_data *data, char **av)
{
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->number_of_philosophers < 2 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || data->number_of_philosophers > 250 )
		return (FAILURE);
	if (av[5])
	{
		data->times_to_eat = ft_atoi(av[5]);
		if (data->times_to_eat <= 0)
			return (FAILURE);
	}
	else
		data->times_to_eat = -1;
	if (init_mutex(data) == FAILURE)
		return(print_error("Error in initializing mutex!!"));
	init_philosophers(data);
	return (SUCCESS);
}