/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:09:03 by kkanig            #+#    #+#             */
/*   Updated: 2023/04/19 12:44:04 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_list *data, int index)
{
	if (control(data))
	{
		pthread_mutex_lock(&data->forks[index]);
		if (is_dead(data, index, "has taken fork\n"))
			return (1);
		pthread_mutex_lock(&data->forks[(index + 1) % data->philo_number]);
		if (is_dead(data, index, "has taken fork\n"))
			return (1);
		if (is_dead(data, index, "is eating\n"))
			return (1);
		pthread_mutex_lock(&data->mutex);
		data->philo[index].eat_number++;
		data->philo[index].last_eat = get_time();
		pthread_mutex_unlock(&data->mutex);
		waiting_time(data->eat_time);
		pthread_mutex_unlock(&data->forks[index]);
		pthread_mutex_unlock(&data->forks[(index + 1) % data->philo_number]);
	}
	else
		return (1);
	return (0);
}

int	thinking(t_list *data, int index)
{
	if (is_dead(data, index, "is thinking\n"))
		return (1);
	return (0);
}

int	sleeping(t_list *data, int index)
{
	if (is_dead(data, index, "is sleeping\n"))
		return (1);
	waiting_time(data->sleep_time);
	return (0);
}

void	waiting_time(int time)
{
	unsigned long	time1;

	time1 = get_time() + time;
	while (get_time() <= time1)
		usleep(100);
}
