/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:54:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/07 07:27:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, int msg)
{
	int	time;

	pthread_mutex_lock(&philo->data->write);
	time = get_time() - philo->data->start_time;
	if (philo->data->is_dead == 0)
	{
		if (msg == 1)
			printf("\033[37m%d %d %s\033[0m\n", time, philo->id, MSG_FORK);
		if (msg == 2)
			printf("\033[32m%d %d %s\033[0m\n", time, philo->id, MSG_EATING);
		if (msg == 3)
			printf("\033[36m%d %d %s\033[0m\n", time, philo->id, MSG_SLEEPING);
		if (msg == 4)
			printf("\033[33m%d %d %s\033[0m\n", time, philo->id, MSG_THINKING);
		if (msg == 5)
			printf("\033[31m%d %d %s\033[0m\n", time, philo->id, MSG_DIED);
	}
	pthread_mutex_unlock(&philo->data->write);
}
