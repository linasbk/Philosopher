/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:36 by lsabik            #+#    #+#             */
/*   Updated: 2023/02/19 22:55:44 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	init_mutex(t_philosopher *philo)
{
	int	i;

	i = -1;
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->forks)
	{
		while (++i < philo->data->nb_of_philosopher)
		{
			if (pthread_mutex_init(&(philo->forks[i]), NULL) != 0)
			{	
				// free(philo->forks);
            	return FAILURE;
			}
			i++;
		}
		return (SUCCESS);
	}
	return (FAILURE);
}

int	init_philosophers(t_philosopher *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->nb_of_philosopher)
	{
		philo[i].fork_id = i;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % philo->data->nb_of_philosopher;
		philo[i].t_last_meal = get_time();
		while (philo[i].t_last_meal < get_time())
			pthread_create(&(philo[i].thread), NULL, philo_action, &philo[i]);
		i++;
	}
	i = 0;
    while (i < philo->data->nb_of_philosopher)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }
	return (SUCCESS);
}

int	init_args(t_data *data, char **av)
{
	data->nb_of_philosopher = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		data->times_to_eat = ft_atoi(av[5]);
		if (data->times_to_eat <= 0)
			return (FAILURE);
	}
	else
		data->times_to_eat = -1;
	if (data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || data->nb_of_philosopher < 0)
		return (FAILURE);
	return (SUCCESS);
}

int	init(t_philosopher *philo, char **av)
{
	philo->data = (t_data *)malloc(sizeof(t_data));
	if (!philo->data)
		return (FAILURE);
	if (!init_args(philo->data, av))
		return (print_error("Arguments are not valid!!"));
	if (init_mutex(philo) == FAILURE)
		return (print_error("Error in initializing mutex!!"));
		if (!init_philosophers(philo))
			return (FAILURE);
	return (SUCCESS);
}
