/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:33:08 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/04 20:09:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	free_everythings(t_data *data)
{
	int	i;

	if (data->philos)
		free(data->philos);
	if (data->threads)
		free(data->threads);
	if (data->forks)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	return (0);
}
