/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilis2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:14:05 by lsabik            #+#    #+#             */
/*   Updated: 2023/04/12 03:34:29 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach_all(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->last_meal));
	while (i < data->nb_of_philosopher)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	free(data->forks);
	free(data->philo);
	free(data);
}

int	check_nb_of_meals(t_philosopher *philo, t_data *data)
{
	if (data->nb_of_meals != -1)
	{
		pthread_mutex_lock(&philo->data->eating);
		if (philo->data->eat >= data->nb_of_meals * data->nb_of_philosopher)
		{
			pthread_mutex_lock(&philo->data->print);
			data->dead = 1;
			pthread_mutex_unlock(&philo->data->print);
			return (FAILURE);
		}
		pthread_mutex_unlock(&philo->data->eating);
	}
	return (SUCCESS);
}

int	philo_dead(t_philosopher *philo, t_data *data)
{
	int	i;

	while (!(data->dead))
	{
		i = 0;
		while (i < data->nb_of_philosopher)
		{
			if (check_nb_of_meals(philo, data) == FAILURE)
				return (FAILURE);
			pthread_mutex_lock(&philo->data->last_meal);
			if (get_time() - philo[i].t_last_meal > data->time_to_die)
			{
				pthread_mutex_lock(&philo->data->print);
				data->dead = 1;
				pthread_mutex_unlock(&philo->data->print);
				print_out(&philo[i], "died");
				return (FAILURE);
			}
			pthread_mutex_unlock(&philo->data->last_meal);
			i++;
		}
	}
	return (SUCCESS);
}

int	join_free(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	if (philo_dead(philo, data) == FAILURE)
		return (FAILURE);
	while (i < data->nb_of_philosopher)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			detach_all(data);
			return (FAILURE);
		}
		i++;
	}
	detach_all(data);
	return (SUCCESS);
}

void	my_sleep(long long time)
{
	long long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(200);
}
