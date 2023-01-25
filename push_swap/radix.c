/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:58:39 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/17 17:47:10 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_list *list)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < bit(list))
	{
		len = 0;
		while (len < list->fakealen)
		{
			if ((list->stacka[0] >> i) & 1)
				ra(list);
			else
				pb(list);
			len++;
		}
		while (list->blen)
			pa(list);
		i++;
	}
	back_fill_stack(list);
}
