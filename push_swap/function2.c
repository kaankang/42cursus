/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:58:11 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/25 17:29:09 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *list)
{
	int	i;
	int	y;
	int	*arr;

	y = 0;
	i = 1;
	if (list->alen)
	{
		list->alen++;
		arr = malloc(sizeof(int) * list->alen + 2);
		while (y < list->alen)
			arr[i++] = list->stacka[y++];
		arr[0] = list->stackb[0];
		down_up(list->stackb, list->blen);
		free(list->stacka);
		list->stacka = arr;
		list->blen--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_list *data)
{
	int	i;
	int	y;
	int	*arr;

	y = 0;
	i = 1;
	if (data->alen)
	{
		data->blen++;
		arr = malloc(sizeof(int) * data->blen + 1);
		while (y < data->blen)
			arr[i++] = data->stackb[y++];
		arr[0] = data->stacka[0];
		free(data->stackb);
		data->stackb = arr;
		data->alen--;
		down_up(data->stacka, data->alen);
		write(1, "pb\n", 3);
	}
}

void	ra(t_list *list)
{
	int	temp;

	if (list->alen > 1)
	{
		temp = list->stacka[0];
		down_up(list->stacka, list->alen);
		list->stacka[list->alen - 1] = temp;
		if (list->rrcontrol)
			write(1, "ra\n", 3);
	}
}

void	rb(t_list *list)
{
	int	temp;

	if (list->alen > 1)
	{
		temp = list->stackb[0];
		down_up(list->stackb, list->blen);
		list->stackb[list->blen - 1] = temp;
		if (list->rrcontrol)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list *list)
{
	list->rrcontrol = 0;
	ra(list);
	rb(list);
	list->rrcontrol = 1;
	write(1, "rr\n", 3);
}
