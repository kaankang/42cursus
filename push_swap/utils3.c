/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:58:58 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/17 17:20:12 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_control(t_list *list)
{
	int	i;
	int	j;

	j = 1;
	while (list->error[j])
	{
		i = 0;
		while (list->error[j][i])
		{
			if (list->error[j][i] == '-' || list->error[j][i] == '+')
			{
				i++;
				if ((list->error[j][i] < 48 || list->error[j][i] > 57)
				&& (list->error[j][i] != 32))
					return (if_error());
			}
			if ((list->error[j][i] < 48 || list->error[j][i] > 57)
			&& (list->error[j][i] != 32))
				return (if_error());
		i++;
		}
	j++;
	}
	return (1);
}

int	true_sort(t_list *list)
{
	int	a;

	a = 0;
	while (a < list->alen - 1)
	{
		if ((list->stacka[a] < list->stacka[a + 1]))
				a++;
		else
			return (1);
	}
	return (0);
}

int	same_control(t_list *list)
{
	int	a;
	int	b;

	a = 0;
	while (a < list->alen)
	{
		b = 0;
		while (b < list->alen)
		{
			if ((list->stacka[a] == list->stacka[b]) && (a != b))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			else
				b++;
		}
	a++;
	}
	return (1);
}
