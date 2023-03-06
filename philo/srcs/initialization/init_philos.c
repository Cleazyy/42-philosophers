/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:58:01 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 21:56:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philo)
		return (print_error("malloc() failed."));
	i = 0;
	while (i < data->nb_philos)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = &data->fork[i];
		data->philo[i].right_fork = &data->fork[i - 1];
		if (i == 0)
			data->philo[i].right_fork = &data->fork[data->nb_philos - 1];
		data->philo[i].meal_count = 0;
		data->philo[i].last_meal = data->start_time;
		data->philo[i].eating = 0;
		data->philo[i].status = 0;
		if (pthread_mutex_init(&data->philo[i].lock, NULL))
			return (print_error("pthread_mutex_init() failed"));
		i++;
	}
	return (1);
}
