/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:36 by lsabik            #+#    #+#             */
/*   Updated: 2023/04/10 17:38:33 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = ft_calloc(sizeof(pthread_mutex_t), data->nb_of_philosopher);
	if (!data->forks)
		return (print_error("error in allocation!!"));
	while (i < data->nb_of_philosopher)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (free(data), print_error("error in mutex init!!"));
		i++;
	}
	if (pthread_mutex_init(&(data->print), NULL) != 0)
		return (free(data), print_error("error in mutex init!!"));
	if (pthread_mutex_init(&(data->eating), NULL) != 0)
		return (free(data), print_error("error in mutex init!!"));
	if (pthread_mutex_init(&(data->last_meal), NULL) != 0)
		return (free(data), print_error("error in mutex init!!"));
	return (SUCCESS);
}

int	init_philosophers(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nb_of_philosopher)
	{
		philo[i].fork_id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->nb_of_philosopher;
		philo[i].data = data;
		pthread_mutex_lock(&philo->data->last_meal);
		philo[i].t_last_meal = get_time();
		pthread_mutex_unlock(&philo->data->last_meal);
		if (pthread_create(&(philo[i].thread), NULL, philo_action, \
			&philo[i]) != 0)
			return (print_error("error in thread creation!!"));
		i++;
	}
	if (join_free(data, philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_parser(t_data *data)
{
	if (data->time_to_die < 0 || data->time_to_eat < 0 || \
		data->time_to_sleep < 0 || data->time_to_die > INT_MAX \
		|| data->time_to_eat > INT_MAX || data->time_to_sleep > INT_MAX
		|| data->nb_of_philosopher <= 0 || data->nb_of_philosopher > 200)
		return (FAILURE);
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
		data->nb_of_meals = ft_atoi(av[5]);
		if (data->nb_of_meals <= 0 || data->nb_of_meals > INT_MAX)
			return (FAILURE);
	}
	else
		data->nb_of_meals = -1;
	data->dead = 0;
	data->eat = 0;
	if (ft_parser(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	init(t_data *data, char **av)
{
	if (!init_args(data, av))
		return (free(data), print_error("Arguments are not valid!!"));
	data->philo = (t_philosopher *)malloc(sizeof(t_philosopher)
			* data->nb_of_philosopher);
	if (!data->philo)
		return (print_error("Error in allocation!!"));
	if (init_mutex(data) == FAILURE)
		return (print_error("Error in initializing mutex!!"));
	if (!init_philosophers(data, data->philo))
		return (FAILURE);
	return (SUCCESS);
}
