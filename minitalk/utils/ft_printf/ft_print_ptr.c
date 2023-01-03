/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:04:46 by kkanig            #+#    #+#             */
/*   Updated: 2022/11/15 15:19:59 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long p)
{
	int	len;

	len = 0;
	if (p >= 16)
		len += ft_print_ptr(p / 16);
	if ((p % 16) < 10)
		len += ft_putchar((p % 16) + '0');
	else
		len += ft_putchar((p % 16) - 10 + 'a');
	return (len);
}
