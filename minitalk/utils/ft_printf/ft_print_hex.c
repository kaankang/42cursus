/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:32:25 by kkanig            #+#    #+#             */
/*   Updated: 2022/11/16 13:38:56 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int x, int b)
{
	int	len;

	len = 0;
	if (x >= 16)
		len += ft_print_hex(x / 16, b);
	if ((x % 16) < 10)
		len += ft_putchar((x % 16) + '0');
	else
	{
		if (b == 0)
			len += ft_putchar((x % 16) - 10 + 'a');
		else
			len += ft_putchar((x % 16) - 10 + 'A');
	}
	return (len);
}
