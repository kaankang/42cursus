/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:19:29 by kkanig            #+#    #+#             */
/*   Updated: 2023/04/19 12:31:47 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_list *data, int index)
{
	unsigned long	time;

	pthread_mutex_lock(&data->mutex);
	time = get_passed_time(data->philo[index].last_eat);
	if ((int)time >= data->dead_time)
	{
		data->dead = 1;
		printf("%d      %d died", (int)get_passed_time(data->start_time),
			data->philo[index].philo_id);
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex);
	return (0);
}

int	is_dead(t_list *data, int index, char *str)
{
	pthread_mutex_lock(&data->mutex);
	if (data->philo[index].eat_number == data->philo_max_eat)
	{
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	if (data->dead == 0)
	{
		printf("%-10d   %d %s", (int)get_passed_time(data->start_time),
			data->philo[index].philo_id, str);
		pthread_mutex_unlock(&data->mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->forks[index]);
	pthread_mutex_unlock(&data->forks[(index + 1) % data->philo_number]);
	pthread_mutex_unlock(&data->mutex);
	return (1);
}

int	control(t_list *data)
{
	pthread_mutex_lock(&data->mutex);
	if (data->dead == 0)
	{
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex);
	return (0);
}

void	dead_control(t_list *data)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		if (!control(data) || eat_philo(data))
			break ;
		while (i < data->philo_number)
		{
			if (dead(data, i) || eat_philo(data))
				break ;
			i++;
		}
	}
}
