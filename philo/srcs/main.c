/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:15:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 13:47:55 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (print_error("wrong numbers of arguments."));
	if (!check_args(ac, av))
		return (print_error("arugments should only contain numbers."));
	if (!parse_args(&data, ac, av))
		return (print_error("arguments contain invalid numbers."));
	if (!initialization(&data))
		return (print_error("initilization."));
	free_everythings(&data);
	return (0);
}
