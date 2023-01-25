/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:58:52 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/17 15:57:47 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_fill_stack(t_list *list)
{
	int	i;

	i = 0;
	while (list->alen > i)
	{
		list->stacka[i] = list->fakea[i];
		i++;
	}
}

void	sort2(t_list *list)
{
	if (list->stacka[0] > list->stacka[1])
		sa(list);
}

void	sort3(t_list *list)
{
	if (list->stacka[0] > list->stacka[1]
		&& list->stacka[1] > list->stacka[2])
	{
		sa(list);
		rra(list);
	}
	else if (list->stacka[0] > list->stacka[2]
		&& list->stacka[2] > list->stacka[1])
		ra(list);
	else if (list->stacka[1] > list->stacka[0]
		&& list->stacka[0] > list->stacka[2])
	{
		rra(list);
	}
	else if (list->stacka[1] > list->stacka[2]
		&& list->stacka[2] > list->stacka[0])
	{
		sa(list);
		ra(list);
	}
	else if (list->stacka[2] > list->stacka[0]
		&& list->stacka[0] > list->stacka[1])
	{	
		sa(list);
	}
}

void	min_stacka(t_list *list)
{
	int	i;

	i = 0;
	list->temp = list->stacka[0];
	while (i < list->alen)
	{
		if (list->temp > list->stacka[i])
		{	
			list->temp = list->stacka[i];
			list->minsize = i;
		}
		i++;
	}
	minpush(list);
}

void	minpush(t_list *list)
{
	int	k;

	k = 0;
	while (k < list->alen)
	{
		if (list->minsize == 4)
		{
			rra(list);
			list->minsize = 0;
		}
		if (list->stacka[0] == list->temp)
		{
			pb(list);
			k = list->alen;
		}
		else
			ra(list);
		k++;
	}
}
