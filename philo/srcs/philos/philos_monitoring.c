/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_monitoring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:21:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/08 18:57:42 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_last_meal(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (get_time() >= data->philo[i].last_meal + data->time_to_die)
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
	int	all_meals_eaten;
	int	i;

	all_meals_eaten = 1;
	i = 0;
	while (i < data->nb_philos)
	{
		if (data->philo[i].meal_count < data->nb_meals)
		{
			all_meals_eaten = 0;
			break ;
		}
		i++;
	}
	if (all_meals_eaten == 1 && data->is_dead == 0)
	{
		pthread_mutex_lock(&data->lock);
		data->is_dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
}

void	death_monitoring(t_data *data)
{
	while (data->is_dead == 0)
	{
		check_last_meal(data);
		if (data->nb_meals == -1)
			continue ;
		check_nb_meals(data);
	}
}
