/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:08:25 by kkanig            #+#    #+#             */
/*   Updated: 2023/04/19 12:43:04 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*loop(void *data)
{
	int		index;
	t_list	*list;

	list = data;
	pthread_mutex_lock(&list->mutex);
	index = list->philo_index;
	pthread_mutex_unlock(&list->mutex);
	while (1)
	{
		if (list->philo_max_eat != list->philo[index].eat_number)
		{
			if (!control(list) || eating(list, index))
				break ;
			if (!control(list) || thinking(list, index))
				break ;
			if (!control(list) || sleeping(list, index))
				break ;
		}
		else
			break ;
	}
	return (0);
}

void	*one_philo(void *data)
{
	t_list	*list;

	list = data;
	printf("%-10d   %d %s", (int)get_passed_time(list->start_time),
		list->philo[0].philo_id, "has taken fork\n");
	waiting_time(list->dead_time);
	printf("%d      %d died", (int)get_passed_time(list->start_time),
		list->philo[0].philo_id);
	return (0);
}

void	creat_data(t_list *data)
{
	int	j;
	int	i;

	i = 0;
	data->start_time = get_time();
	data->dead = 0;
	data->philo_index = 0;
	j = data->philo_number;
	data->philo = malloc(sizeof(t_philo) * data->philo_number);
	while (i < j)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].eat_number = 0;
		data->philo[i].last_eat = get_time();
		i++;
	}
}

void	thread_creat(t_list *data)
{
	int	i;

	i = 0;
	if (data->philo_number == 1)
	{
		pthread_create(&data->philo[0].philo, NULL, &one_philo, data);
		usleep(100);
		pthread_join(data->philo[0].philo, NULL);
		return ;
	}
	else
	{
		while (i < data->philo_number)
		{
			pthread_mutex_lock(&data->mutex);
			data->philo_index = i;
			pthread_mutex_unlock(&data->mutex);
			pthread_create(&data->philo[i++].philo, NULL, &loop, data);
			usleep(100);
		}
		dead_control(data);
		i = 0;
		while (i < data->philo_number)
			pthread_join(data->philo[i++].philo, NULL);
	}
}

void	mutex_creat(t_list *data)
{
	int	i;
	int	j;

	j = data->philo_number;
	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * j);
	while (i < j)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->mutex, NULL);
}
