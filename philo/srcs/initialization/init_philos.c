/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:58:01 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/05 22:19:43 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
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
		data->philos[i].left_fork = &data->forks[i];
		if (i == 0)
			data->philos[0].right_fork = &data->forks[data->nb_philos - 1];
		else
			data->philos[i].right_fork = &data->forks[i - 1];
		data->philos[i].meal_count = 0;
		data->philos[i].time_to_die = data->t_die;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		if (pthread_mutex_init(&data->philos[i].lock, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
