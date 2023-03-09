/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:04:48 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 16:41:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		is_dead;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->data->lock);
	is_dead = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->lock);
	if (!is_dead)
		actions_loop(philo);
	return (NULL);
}
