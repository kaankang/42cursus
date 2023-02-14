/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:08 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/30 18:34:43 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test(t_list *data, int y, int x)
{
	if ((data->test[y + 1][x] == 'C' || data->test[y + 1][x] == '0')
		|| data->test[y + 1][x] == 'P')
	{
		data->test[y + 1][x] = '.';
		test(data, y + 1, x);
	}
	if ((data->test[y - 1][x] == 'C' || data->test[y - 1][x] == '0')
		|| data->test[y - 1][x] == 'P')
	{
		data->test[y - 1][x] = '.';
		test(data, y - 1, x);
	}
	if ((data->test[y][x + 1] == 'C' || data->test[y][x + 1] == '0')
		|| data->test[y][x + 1] == 'P')
	{
		data->test[y][x + 1] = '.';
		test(data, y, x + 1);
	}
	if ((data->test[y][x - 1] == 'C' || data->test[y][x - 1] == '0')
		|| data->test[y][x - 1] == 'P')
	{
		data->test[y][x - 1] = '.';
		test(data, y, x - 1);
	}
}

void	map_split(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->test = ft_split(data->map, '\n');
	while (data->test[i])
	{
		j = 0;
		while (data->test[i][j])
		{
			if (data->test[i][j] == 'P')
			{
				data->map_y = i;
				data->map_x = j;
				break ;
			}
			j++;
		}
		i++;
	}
	test(data, data->map_y, data->map_x);
	map_coin_control(data);
	map_exit(data);
}

void	map_coin_control(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->test[i])
	{
		j = 0;
		while (data->test[i][j])
		{
			if (data->test[i][j] == 'C')
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	map_exit(t_list *data)
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
			if (data->split[i][j] == 'E')
			{
				data->exitx = i;
				data->exity = j;
				break ;
			}
			j++;
		}
		i++;
	}
	map_exit_control(data);
}

void	map_exit_control(t_list *data)
{
	if (data->test[data->exitx - 1][data->exity] == '.')
		return ;
	else if (data->test[data->exitx + 1][data->exity] == '.')
		return ;
	else if (data->test[data->exitx][data->exity - 1] == '.')
		return ;
	else if (data->test[data->exitx][data->exity + 1] == '.')
		return ;
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}
