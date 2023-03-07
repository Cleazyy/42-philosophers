/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:42:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/07 07:21:17 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clear_data(t_data *data)
{
	if (data->fork)
		free(data->fork);
	if (data->philo)
		free(data->philo);
	if (data->tid)
		free(data->tid);
}

static int	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_destroy(&data->fork[i]))
			return (print_error("pthread_mutex_destroy() failed."));
		i++;
	}
	if (pthread_mutex_destroy(&data->write))
		return (print_error("pthread_mutex_destroy() failed."));
	if (pthread_mutex_destroy(&data->lock))
		return (print_error("pthread_mutex_destroy() failed."));
	return (0);
}

static int	destroy_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_join(data->tid[i], NULL))
			return (print_error("pthread_join() failed."));
		i++;
	}
	return (0);
}

void	free_everythings(t_data *data)
{
	destroy_threads(data);
	destroy_mutexes(data);
	clear_data(data);
}
