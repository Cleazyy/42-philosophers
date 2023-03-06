/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:52:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 19:17:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (print_error("mutex initialization failed"));
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		return (print_error("mutex initialization failed"));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (print_error("malloc allocation failed."));
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (print_error("mutex initialization failed"));
		i++;
	}
	return (1);
}
