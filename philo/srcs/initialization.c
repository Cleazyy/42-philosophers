/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:57:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/04 20:09:41 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		return (0);
	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		i++;
	}
	return (1);
}

static int	init_threads(t_data *data)
{
	int	i;

	data->threads = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->threads)
		return (0);
	i = 0;
	data->start_time = get_time();
	while (i < data->nb_philos)
	{
		// if (pthread_create(&data->threads[i], NULL, &routine, &data->philos[i]) != 0)
		// 	return (0);
		i++;
	}
	return (1);
}

int	initialization(t_data *data)
{
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	if (!init_threads(data))
		return (0);
	return (1);
}
