/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:43:26 by lsabik            #+#    #+#             */
/*   Updated: 2023/02/19 22:57:38 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	philo_eat(t_philosopher *philo)
{
	printf("philo:%d eat\n",philo->fork_id);
}

void	*philo_action(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)argv;
	philo_eat(philo);
	// philo_sleep();
	// philo_think();
	printf("salam\n");
	return (NULL);
}
