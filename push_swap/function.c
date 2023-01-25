/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:57:49 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/16 11:57:52 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list)
{
	int	temp;

	if (list->alen > 1)
	{
		temp = list->stacka[0];
		list->stacka[0] = list->stacka[1];
		list->stacka[1] = temp;
		if (list->sscontrol)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list *list)
{
	int	temp;

	if (list->alen > 1)
	{
		temp = list->stackb[0];
		list->stackb[0] = list->stackb[1];
		list->stackb[1] = temp;
		if (list->sscontrol)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list *list)
{
	list->sscontrol = 0;
	sa(list);
	sb(list);
	list->sscontrol = 1;
	write(1, "ss\n", 3);
}
