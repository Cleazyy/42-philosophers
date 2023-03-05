/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:57:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/05 21:05:40 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialization(t_data *data)
{
	data->is_dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	if (!init_threads(data))
		return (1);
	return (1);
}
