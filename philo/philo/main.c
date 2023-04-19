/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:08:46 by kkanig            #+#    #+#             */
/*   Updated: 2023/04/19 13:12:39 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_list	*data;

	if (ac == 5 || ac == 6)
	{
		data = malloc(sizeof(t_list));
		arg_control(ac, av, data);
		if (error_control(data))
		{
			mutex_creat(data);
			creat_data(data);
			thread_creat(data);
			mutex_destroy(data);
		}
	}
	else
		printf("Error\n");
}
