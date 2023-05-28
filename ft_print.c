/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:45 by lsabik            #+#    #+#             */
/*   Updated: 2023/04/06 20:39:33 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

int	print_error(char *str)
{
	printf("Error:\n%s \n", str);
	return (FAILURE);
}

void	print_out(t_philosopher *philo, char *str)
{
	long	time;

	pthread_mutex_lock(&(philo->data->print));
	time = get_time() - philo->data->start_time;
	if (philo->data->dead == 0 || !ft_strcmp(str, "died"))
		printf("%ld %d %s\n", time, philo->fork_id, str);
	pthread_mutex_unlock(&(philo->data->print));
}
