/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:51 by lsabik            #+#    #+#             */
/*   Updated: 2023/02/19 22:52:33 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int ac, char **av)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (philo)
	{
		if (ac != 5 && ac != 6)
			return (print_error("Wrong arguments!"));
		while(1)
		{
			if (!init(philo, av))
				break;
		}
		// return (SUCCESS);
	}
	return (FAILURE);
}
