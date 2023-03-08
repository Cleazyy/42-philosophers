/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:46:06 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/07 19:32:33 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_data *data)
{
	int	i;

	data->tid = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->tid)
		return (print_error("malloc() tid failed."));
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philo[i]))
			return (print_error("pthread_create() tid failed."));
		ft_usleep(1);
		i++;
	}
	return (1);
}
