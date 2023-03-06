/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:54:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 19:17:16 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, int msg)
{
	int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->write);
	if (msg == 5 && !philo->data->is_dead)
	{
		printf("\033[31m%d %d %s\033[0m\n", time, philo->id, DIED_MSG);
		philo->data->is_dead = 1;
	}
	if (!philo->data->is_dead)
	{
		if (msg == 1)
			printf("\033[37m%d %d %s\033[0m\n", time, philo->id, FORKS_MSG);
		if (msg == 2)
			printf("\033[32m%d %d %s\033[0m\n", time, philo->id, EATING_MSG);
		if (msg == 3)
			printf("\033[36m%d %d %s\033[0m\n", time, philo->id, SLEEPING_MSG);
		if (msg == 4)
			printf("\033[33m%d %d %s\033[0m\n", time, philo->id, THINKING_MSG);
	}
	pthread_mutex_unlock(&philo->data->write);
}
