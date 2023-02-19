/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:51 by lsabik            #+#    #+#             */
/*   Updated: 2023/02/19 20:20:07 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (ac != 5 && ac != 6)
		return (print_error("Wrong arguments!"));
	if (init(data, av) == SUCCESS)
		printf("good!\n");
	return (SUCCESS);
}
