/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:36:49 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 18:46:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t	g_lock;
int				g_count = 0;

void	*routine(void *arg)
{
	int	i;

	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&g_lock);
		g_count++;
		pthread_mutex_unlock(&g_lock);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;

	pthread_mutex_init(&g_lock, NULL);
	pthread_create(&tid1, NULL, &routine, NULL);
	pthread_create(&tid2, NULL, &routine, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&g_lock);
	printf("g_count: %d\n", g_count);
}
