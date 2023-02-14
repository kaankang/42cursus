/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:41 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/31 15:55:11 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard(int key, t_list *data)
{
	if (key == 53)
		exit(1);
	if (key == 0 && data->split[data->map_y][data->map_x - 1] != '1')
		left_move(data);
	if (key == 2 && data->split[data->map_y][data->map_x + 1] != '1')
		right_move(data);
	if (key == 13 && data->split[data->map_y - 1][data->map_x] != '1')
		up_move(data);
	if (key == 1 && data->split[data->map_y + 1][data->map_x] != '1')
		down_move(data);
	return (1);
}

void	left_move(t_list *data)
{
	if (data->split[data->map_y][data->map_x - 1] == 'C')
	{
		data->coin--;
		data->split[data->map_y][data->map_x - 1] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_x--;
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[2],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_x--;
		mlx_put_image_to_window(data->mlx, data->window, data->image[2],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x - 1] == 'E'
			&& data->coin == 0)
		exit(1);
}

void	right_move(t_list *data)
{
	if (data->split[data->map_y][data->map_x + 1] == 'C')
	{
		data->coin--;
		data->split[data->map_y][data->map_x + 1] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_x++;
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[2],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_x++;
		mlx_put_image_to_window(data->mlx, data->window, data->image[2],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x + 1] == 'E'
			&& data->coin == 0)
		exit(1);
}

void	up_move(t_list *data)
{
	if (data->split[data->map_y - 1][data->map_x] == 'C')
	{
		data->coin--;
		data->split[data->map_y - 1][data->map_x] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_y--;
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[2],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y - 1][data->map_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_y--;
		mlx_put_image_to_window(data->mlx, data->window, data->image[2],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y - 1][data->map_x] == 'E'
			&& data->coin == 0)
		exit(1);
}

void	down_move(t_list *data)
{
	if (data->split[data->map_y + 1][data->map_x] == 'C')
	{
		data->coin--;
		data->split[data->map_y + 1][data->map_x] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_y++;
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[2],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y + 1][data->map_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_y++;
		mlx_put_image_to_window(data->mlx, data->window, data->image[2],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y + 1][data->map_x] == 'E'
			&& data->coin == 0)
		exit(1);
}
