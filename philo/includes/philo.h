/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:17:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/08 15:19:09 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define MSG_FORK "has taken a fork"
# define MSG_EATING "is eating"
# define MSG_SLEEPING "is sleeping"
# define MSG_THINKING "is thinking"
# define MSG_DIED "died"

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				meal_count;
	int				last_meal;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				start_time;
	int				is_dead;
	pthread_t		*tid;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

/* args */
int		check_args(int ac, char **av);
int		parse_args(t_data *data, int ac, char **av);
/* initialization */
int		init_mutexes(t_data *data);
int		init_philos(t_data *data);
int		init_threads(t_data *data);
int		init_simulation(t_data *data);
/* philos */
void	actions_loop(t_philo *philo);
void	death_monitoring(t_data *data);
void	*routine(void *philo_pointer);
void	print_msg(t_philo *philo, int msg);
/* utils */
int		print_error(char *error);
int		get_time(void);
void	ft_usleep(int time);
void	free_everythings(t_data *data);

#endif