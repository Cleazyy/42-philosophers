/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:54:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/05 22:19:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *str, t_philo *philo)
{
	int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->write);
	if (ft_strcmp(DIED_MSG, str) == 0 && philo->data->is_dead == 0)
	{
		printf("%d %d %s\n", time, philo->id, str);
		philo->data->is_dead = 1;
	}
	if (!philo->data->is_dead)
		printf("%d %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}
