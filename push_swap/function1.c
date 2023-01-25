/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:58:03 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/16 11:58:07 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *list)
{
	int	temp;

	if (list->alen > 1)
	{
		temp = list->stacka[list->alen - 1];
		down_move(list);
		list->stacka[0] = temp;
		if (list->rrrcontrol)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list *list)
{
	int	temp;

	if (list->alen > 1)
	{
		temp = list->stackb[0];
		down_move(list);
		list->stackb[list->blen - 1] = temp;
		if (list->rrrcontrol)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list *list)
{
	list->rrrcontrol = 0;
	rra(list);
	rrb(list);
	list->rrrcontrol = 1;
	write(1, "rrr\n", 4);
}

void	down_up(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = 0;
}

void	down_move(t_list *list)
{
	int	i;
	int	temp;
	int	*newarr;

	i = 1;
	temp = list->stacka[list->alen - 1];
	newarr = malloc(sizeof(int) * list->alen + 1);
	while (i < list->alen)
	{
		newarr[i] = list->stacka[i - 1];
		i++;
	}
	newarr[i] = temp;
	free(list->stacka);
	list->stacka = newarr;
}
