/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:43:26 by lsabik            #+#    #+#             */
/*   Updated: 2023/04/07 16:53:54 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->data->forks[philo->left_fork]));
	print_out(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->data->forks[philo->right_fork]));
	print_out(philo, "has taken a fork");
}

void	down_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&(philo->data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->data->forks[philo->right_fork]));
}

void	philo_eat(t_philosopher *philo)
{
	take_forks(philo);
	print_out(philo, "is eating");
	pthread_mutex_lock(&philo->data->last_meal);
	philo->t_last_meal = get_time();
	pthread_mutex_unlock(&philo->data->last_meal);
	my_sleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->eating);
	philo->data->eat++;
	pthread_mutex_unlock(&philo->data->eating);
	down_forks(philo);
}

void	philo_sleep_think(t_philosopher *philo)
{
	print_out(philo, "is sleeping");
	my_sleep(philo->data->time_to_sleep);
	print_out(philo, "is thinking");
}

void	*philo_action(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)argv;
	if (philo->fork_id & 1)
		usleep(100);
	while (1)
	{
		philo_eat(philo);
		philo_sleep_think(philo);
	}
	return (NULL);
}
