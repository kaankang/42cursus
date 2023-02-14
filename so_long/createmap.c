/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:18 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/31 13:16:58 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cpe_control(t_list *data)
{
	int	i;

	data->coin = 0;
	data->player = 0;
	data->exit = 0;
	data->step = 0;
	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == 'C')
			data->coin++;
		if (data->map[i] == 'E')
			data->exit++;
		if (data->map[i] == 'P')
			data->player++;
		i++;
	}
	if ((data->player != 1 || data->exit != 1) || data->coin == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	side_wall_control(t_list *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < data->line - 1)
	{
		if (data->split[i][0] != '1' || data->split[i][data->column - 1] != '1')
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

char	map_wall_control(t_list *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->split[i][j])
	{
		if ((data->split[0][j] != '1') || (data->split[data->line
				- 1][j] != '1'))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		j++;
	}
	map_character_control(data);
	side_wall_control(data);
	cpe_control(data);
	map_control(data);
	return (1);
}

void	create_map(t_list *data, char *file)
{
	data->line = 0;
	data->column = 0;
	data->fd = open(file, O_RDONLY);
	data->map = get_next_line(data->fd);
	data->split = ft_split(data->map, '\n');
	while (data->split[data->line])
	{
		while (data->split[data->line][data->column])
			data->column++;
		data->line++;
	}
	if (data->fd < 0)
		write(1, "Error\n", 6);
}

void	map_control(t_list *data)
{
	int	i;
	int	a;
	int	b;

	b = 0;
	i = 0;
	a = 0;
	while (data->split[a])
	{
		b = 0;
		while (data->split[a][b])
			b++;
		if (data->column != b)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		a++;
	}
}
