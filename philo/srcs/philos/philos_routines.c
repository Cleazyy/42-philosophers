/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:04:48 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 09:36:20 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->time_to_die = philo->data->t_die + get_time();
	if (pthread_create(&philo->t1, NULL, &death_monitoring, (void *)philo))
		return (NULL);
	while (philo->data->is_dead == 0)
		execute_actions(philo);
	if (pthread_join(philo->t1, NULL))
		return (NULL);
	return (NULL);
}

void	*death_monitoring(void *arg)
{
	t_philo	*philo;
	int		now;

	philo = (t_philo *) arg;
	while (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		now = get_time();
		if (now >= philo->time_to_die && philo->eating == 0)
			print_msg(philo, 5);
		if (philo->meal_count == philo->data->nb_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->meal_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

void	*monitoring(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	while (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->nb_philos)
			philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}
