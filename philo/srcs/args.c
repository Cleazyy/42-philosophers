/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:42:06 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/04 18:00:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	convert_number(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res < INT_MIN || res > INT_MAX)
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	return ((int) res);
}

int	parse_args(t_data *data, int ac, char **av)
{
	data->nb_philos = convert_number(av[1]);
	data->t_time = convert_number(av[2]);
	data->t_eat = convert_number(av[3]);
	data->t_sleep = convert_number(av[4]);
	data->nb_meals = -1;
	if (data->nb_philos <= 0 || data->t_time <= 0 || data->t_eat <= 0
		|| data->t_sleep <= 0)
		return (0);
	if (ac == 6)
	{
		data->nb_meals = convert_number(av[5]);
		if (data->nb_meals <= 0)
			return (0);
	}
	return (1);
}
