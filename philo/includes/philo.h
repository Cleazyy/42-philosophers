/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:17:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 21:56:58 by fluchten         ###   ########.fr       */
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

# define FORKS_MSG "has taken a fork"
# define EATING_MSG "is eating"
# define SLEEPING_MSG "is sleeping"
# define THINKING_MSG "is thinking"
# define DIED_MSG "died"

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				meal_count;
	int				status;
	int				eating;
	int				last_meal;
	pthread_mutex_t	lock;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_t		*tid;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	int				nb_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meals;
	int				start_time;
	int				is_dead;
	int				finished;
}	t_data;

/* args */
int		check_args(int ac, char **av);
int		parse_args(t_data *data, int ac, char **av);
/* initialization */
int		init_mutexes(t_data *data);
int		init_philos(t_data *data);
int		init_threads(t_data *data);
int		initialization(t_data *data);
/* philos */
void	actions_loop(t_philo *philo);
void	*philo_routine(void *philo_pointer);
void	death_monitoring(t_data *data);
void	print_msg(t_philo *philo, int msg);
/* utils */
int		print_error(char *error);
int		get_time(void);
void	ft_usleep(int time);
void	free_everythings(t_data *data);

#endif