/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:36:48 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/07 13:01:15 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo, int *is_alone)
{
	pthread_mutex_lock(philo->right_fork);
	print_msg(philo, 1);
	if (*is_alone)
	{
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_msg(philo, 1);
}

static void	eat(t_philo *philo)
{
	print_msg(philo, 2);
	pthread_mutex_lock(&philo->data->lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->lock);
	ft_usleep(philo->data->t_eat);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->data->lock);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->data->lock);
	print_msg(philo, 3);
}

static void	think(t_philo *philo)
{
	ft_usleep(philo->data->t_sleep);
	print_msg(philo, 4);
}

void	actions_loop(t_philo *philo)
{
	int	is_alone;

	is_alone = 0;
	if (philo->data->nb_philos == 1)
		is_alone = 1;
	while (philo->data->is_dead == 0)
	{
		take_forks(philo, &is_alone);
		eat(philo);
		drop_forks(philo);
		think(philo);
	}
}
