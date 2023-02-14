/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:49 by kkanig            #+#    #+#             */
/*   Updated: 2023/02/04 15:31:42 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_check(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	a--;
	if ((str[a] != 'r' && str[a - 1] != 'e') && str[a - 2] != 'b')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	map_character_control(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if ((data->split[i][j] != '0' && data->split[i][j] != '1')
				&& data->split[i][j] != 'E')
			{
				if (data->split[i][j] != 'C' && data->split[i][j] != 'P')
				{
					write(1, "Error\n", 6);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

int	window_close(void)
{
	exit(1);
}

void	space_line(t_list *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[0] != '1')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		if (data->map[i] == '\n' && data->map[i + 1] != '1')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_list));
		ber_check(av[1]);
		create_map(data, av[1]);
		space_line(data);
		map_wall_control(data);
		map_split(data);
		ft_window(data);
		mlx_hook(data->window, 2, 1L << 0, keyboard, data);
		mlx_hook(data->window, 17, 0, window_close, NULL);
		mlx_loop(data->mlx);
	}
}
