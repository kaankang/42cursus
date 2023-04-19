/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:08:16 by kkanig            #+#    #+#             */
/*   Updated: 2023/04/19 12:32:29 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_control(int ac, char **av, t_list *data)
{
	data->philo_number = ft_atoi(av[1]);
	data->dead_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->philo_max_eat = ft_atoi(av[5]);
	else
		data->philo_max_eat = -2;
}

int	error_control(t_list *data)
{
	if (data->philo_number == -1 || data->dead_time == -1)
	{
		printf("Error\n");
		return (0);
	}
	if (data->eat_time == -1)
	{
		printf("Error\n");
		return (0);
	}
	if (data->sleep_time == -1 || data->philo_max_eat == -1
		|| data->philo_number == 0)
	{
		printf("Error\n");
		return (0);
	}
	return (1);
}

void	mutex_destroy(t_list *data)
{
	int	i;
	int	j;

	j = 0;
	i = data->philo_number;
	while (j < i)
		pthread_mutex_destroy(&data->forks[j++]);
	pthread_mutex_destroy(&data->mutex);
}

int	eat_philo(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		pthread_mutex_lock(&data->mutex);
		if (data->philo_max_eat != data->philo[i].eat_number)
		{
			pthread_mutex_unlock(&data->mutex);
			return (0);
		}
		pthread_mutex_unlock(&data->mutex);
		i++;
	}
	pthread_mutex_unlock(&data->mutex);
	return (1);
}
