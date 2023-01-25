/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:12:07 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/16 14:12:09 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size(t_list *list, char **av)
{
	int	j;
	int	i;
	int	size;

	size = 0;
	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		list->splitit = ft_split(av[i], ' ');
		while (list->splitit[j])
		{
			size++;
			free (list->splitit[j]);
			j++;
		}
		free (list->splitit);
	i++;
	}
	list->alen = size;
	list->blen = 0;
	list->fakealen = size;
}

void	ft_setup(t_list *list, char **av)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 1;
	flag(list);
	size(list, av);
	list->stackb = malloc(sizeof(int) * list -> alen);
	list->stacka = malloc(sizeof(int) * list -> alen);
	list->fakea = malloc(sizeof(int) * list-> alen);
	while (av[i])
	{
		j = 0;
		list->splitit = ft_split(av[i], ' ');
		while (list->splitit[j])
		{
			list -> stacka[a++] = ft_atoi(list -> splitit[j]);
			free(list->splitit[j]);
			j++;
		}
		i++;
		free(list->splitit);
	}
}

void	flag(t_list *list)
{
	list->sscontrol = 1;
	list->rrcontrol = 1;
	list->rrrcontrol = 1;
}
