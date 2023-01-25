/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:11:38 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/17 14:43:31 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list *list)
{
	if (list->alen == 2)
		sort2(list);
	if (list->alen == 3)
		sort3(list);
	if (list->alen > 3)
	{
		while (list->alen > 3)
			min_stacka(list);
		sort3(list);
		pa(list);
		if (list->blen)
			pa(list);
	}
}

int	if_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	bit(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	j = list->alen - 1;
	while (j)
	{
		j >>= 1;
		i++;
	}
	return (i);
}

void	max_min(void)
{
	write(1, "Error\n", 6);
	exit (0);
}
