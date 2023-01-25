/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:11:54 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/17 17:49:37 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		*stacka;
	int		*stackb;
	char	**splitit;
	int		alen;
	int		blen;
	int		*fakea;
	int		sscontrol;
	int		rrcontrol;
	int		rrrcontrol;
	int		fakealen;
	char	**error;
	int		temp;
	int		minsize;
}	t_list;

long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	size(t_list *list, char **av);
void	ft_setup(t_list *list, char **av);
void	ft_sort(t_list *ps);
void	find_index(t_list *list);
int		find_index1(int a, int *fakea);
void	radix(t_list *list);
void	down_move(t_list *list);
void	ra(t_list *list);
void	rb(t_list *list);
void	sb(t_list *list);
void	pa(t_list *list);
void	pb(t_list *list);
void	sa(t_list *list);
void	sb(t_list *list);
void	rra(t_list *list);
void	rrb(t_list *list);
void	rrr(t_list *list);
void	back_fill_stack(t_list *list);
void	down_up(int *arr, int len);
void	sort2(t_list *list);
void	sort3(t_list *list);
void	min_stacka(t_list *list);
int		bit(t_list *list);
int		error_control(t_list *list);
int		true_sort(t_list *list);
int		same_control(t_list *list);
void	small_sort(t_list *list);
int		if_error(void);
void	max_min(void);
void	flag(t_list *list);
void	minpush(t_list *list);
#endif
