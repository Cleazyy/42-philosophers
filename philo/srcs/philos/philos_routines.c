/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:04:48 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 22:19:28 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->data->is_dead == 0)
		actions_loop(philo);
	return (NULL);
}

void	death_monitoring(t_data *data)
{
	int	i;

	while (data->is_dead == 0)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (get_time() >= data->philo[i].last_meal + data->t_die)
			{
				print_msg(data->philo, 5);
				pthread_mutex_lock(&data->lock);
				data->is_dead = 1;
				pthread_mutex_unlock(&data->lock);
				break ;
			}
			i++;
		}
	}
}
