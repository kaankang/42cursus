/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:19:27 by kkanig            #+#    #+#             */
/*   Updated: 2022/12/25 17:39:38 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	function(pid_t pid, char alpha)
{
	int	n;

	n = 0;
	while (n <= 7)
	{
		if ((alpha >> n) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		n++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
			function(pid, av[2][i++]);
	}
}
