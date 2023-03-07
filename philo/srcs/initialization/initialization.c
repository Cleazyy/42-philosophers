/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:57:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/07 19:18:58 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialization(t_data *data)
{
	data->start_time = get_time();
	data->is_dead = 0;
	if (!init_mutexes(data))
		return (0);
	if (!init_philos(data))
		return (0);
	if (!init_threads(data))
		return (0);
	death_monitoring(data);
	free_everythings(data);
	return (1);
}
