/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:11:59 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/17 17:54:18 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (ac >= 2)
	{
		ft_setup(list, av);
		list->error = av;
		if (error_control(list))
		{
			if (same_control(list) && (true_sort(list)))
			{
				if (list->alen > 5)
				{
					ft_sort(list);
					find_index(list);
					radix(list);
				}
				else
					small_sort(list);
			}
		}
	}
}
