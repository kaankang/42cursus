/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:30 by kkanig            #+#    #+#             */
/*   Updated: 2023/02/04 15:12:44 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window(t_list *data)
{
	data->image = malloc(sizeof(void *) * 5);
	data->mlx = mlx_init();
	data->image[0] = mlx_xpm_file_to_image(data->mlx, PL_FT, &data->image_x,
			&data->image_y);
	data->image[1] = mlx_xpm_file_to_image(data->mlx, PL_TT, &data->image_x,
			&data->image_y);
	data->image[2] = mlx_xpm_file_to_image(data->mlx, PL_DT, &data->image_x,
			&data->image_y);
	data->image[3] = mlx_xpm_file_to_image(data->mlx, PL_ST, &data->image_x,
			&data->image_y);
	data->image[4] = mlx_xpm_file_to_image(data->mlx, PL_XT, &data->image_x,
			&data->image_y);
	data->window = mlx_new_window(data->mlx, 64 * data->column, 64 * data->line,
			"window");
	back_ground(data);
}

void	back_ground(t_list *data)
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
			if (data->split[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->image[1],
					j * 64, i * 64);
			if (data->split[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->image[0],
					j * 64, i * 64);
			back_ground2(data, i, j);
			j++;
		}
		i++;
	}
	put_step(data);
}

void	back_ground2(t_list *data, int i, int j)
{
	if (data->split[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0], j * 64,
			i * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[4], j * 64,
			i * 64);
	}
	if (data->split[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->image[3], j * 64,
			i * 64);
	if (data->split[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0], j * 64,
			i * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[2], j * 64,
			i * 64);
	}
}

void	put_step(t_list *data)
{
	char	*step;

	step = ft_itoa(data->step);
	mlx_put_image_to_window(data->mlx, data->window, data->image[1], 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->image[1], 64, 0);
	mlx_string_put(data->mlx, data->window, 0, 10, 0x0, "STEP =");
	mlx_string_put(data->mlx, data->window, 50, 10, 0x0, step);
	free(step);
}

void	step_plus(t_list *data)
{
	data->step++;
	put_step(data);
}
