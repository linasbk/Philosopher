/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:36 by lsabik            #+#    #+#             */
/*   Updated: 2023/02/19 20:16:51 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philosopher)
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (FAILURE);
	return (SUCCESS);
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philosopher)
	{
		data->philo->fork_id = i;
		pthread_create(&(data->thread), NULL, philo_action, data);
		data->philo->t_last_meal = get_time();
	}
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

int	init(t_data *data, char **av)
{
	if (!init_args(data, av))
		return (print_error("Arguments are not valid!!"));
	if (init_mutex(data) == FAILURE)
		return (print_error("Error in initializing mutex!!"));
	init_philosophers(data);
	return (SUCCESS);
}
