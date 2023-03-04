/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:15:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/04 20:36:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_data(t_data *data)
{
	printf("nb_philos = [%d]\n", data->nb_philos);
	printf("t_time = [%d]\n", data->t_time);
	printf("t_eat = [%d]\n", data->t_eat);
	printf("t_sleep = [%d]\n", data->t_sleep);
	printf("nb_meals = [%d]\n", data->nb_meals);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (print_error("Wrong numbers of arguments."));
	if (!parse_args(&data, ac, av))
		return (print_error("Invalid input arguments."));
	if (!initialization(&data))
		return (print_error("Initilization."));
	print_data(&data);
	free_everythings(&data);
	return (0);
}
