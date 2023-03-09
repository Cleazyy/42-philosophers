/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_monitoring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:21:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 16:39:11 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_last_meal(t_data *data)
{
	int	time_last_meal;
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->lock);
		time_last_meal = data->philo[i].time_last_meal;
		pthread_mutex_unlock(&data->lock);
		if (get_time() >= time_last_meal + data->time_to_die)
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

static void	check_nb_meals(t_data *data)
{
	int	meal_count;
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->lock);
		meal_count = data->philo[i].meal_count;
		pthread_mutex_unlock(&data->lock);
		if (meal_count < data->nb_meals)
			break ;
		i++;
	}
	if (i == data->nb_philos)
	{
		pthread_mutex_lock(&data->lock);
		data->is_dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
}

void	death_monitoring(t_data *data)
{
	int	is_dead;

	pthread_mutex_lock(&data->lock);
	is_dead = data->is_dead;
	pthread_mutex_unlock(&data->lock);
	while (!is_dead)
	{
		check_last_meal(data);
		if (data->nb_meals != -1)
			check_nb_meals(data);
		pthread_mutex_lock(&data->lock);
		is_dead = data->is_dead;
		pthread_mutex_unlock(&data->lock);
	}
}
