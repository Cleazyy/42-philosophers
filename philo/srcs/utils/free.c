/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:42:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 19:19:26 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clear_data(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	if (data->tid)
		free(data->tid);
}

static void	destroy_mutexes(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
		i++;
	}
}

void	free_everythings(t_data *data)
{
	clear_data(data);
	destroy_mutexes(data);
}
