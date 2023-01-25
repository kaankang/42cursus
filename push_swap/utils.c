/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:58:45 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/17 17:06:35 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list *list)
{
	int	i;
	int	j;
	int	small;

	i = 0;
	j = 0;
	while (list->alen != i)
		list->fakea[i++] = list->stacka[j++];
	i = 0;
	while (list->alen != i)
	{
		j = 0;
		while (j < list->alen)
		{
			if (list->fakea[j] > list->fakea[i])
			{
				small = list->fakea[j];
				list->fakea[j] = list->fakea[i];
				list->fakea[i] = small;
			}
			j++;
		}
		i++;
	}
}

int	find_index1(int a, int *fakea)
{
	int	i;

	i = 0;
	while (fakea[i] != a)
		i++;
	return (i);
}

void	find_index(t_list *list)
{
	int	i;

	i = 0;
	while (i != list->alen)
	{
		list->stacka[i] = find_index1(list->stacka[i], list->fakea);
		i++;
	}
}
