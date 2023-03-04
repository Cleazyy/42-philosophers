/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:17:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/04 17:31:49 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
}	t_philo;

typedef struct s_data
{
	int		nb_philos;
	int		t_time;
	int		t_eat;
	int		t_sleep;
	int		nb_meals;
}	t_data;

#endif