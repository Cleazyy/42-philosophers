/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:42:06 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/10 11:10:26 by fluchten         ###   ########.fr       */
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
			return (-1);
		i++;
	}
	return ((int) res);
}

int	parse_args(t_data *data, int ac, char **av)
{
	data->nb_philos = convert_number(av[1]);
	data->time_to_die = convert_number(av[2]);
	data->time_to_eat = convert_number(av[3]);
	data->time_to_sleep = convert_number(av[4]);
	data->nb_meals = -1;
	if (data->nb_philos <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (print_error("args contain invalid numbers."));
	if (ac == 6)
	{
		data->nb_meals = convert_number(av[5]);
		if (data->nb_meals <= 0)
			return (print_error("args contain invalid numbers."));
	}
	return (1);
}
