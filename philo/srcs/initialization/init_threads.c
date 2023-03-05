/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:46:06 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/05 22:19:31 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_data *data)
{
	int			i;
	pthread_t	t0;

	data->tid = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->tid)
		return (0);
	data->start_time = get_time();
	if (data->nb_meals > 0)
	{
		if (pthread_create(&t0, NULL, &monitoring, &data->philos[0]))
			return (0);
	}
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (0);
		ft_usleep(1);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_join(data->tid[i], NULL))
			return (0);
		i++;
	}
	return (1);
}
