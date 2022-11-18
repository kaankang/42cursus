/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:42:33 by kkanig            #+#    #+#             */
/*   Updated: 2022/11/15 15:57:00 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nb)
{
	int	len;

	len = 0;
	if (nb <= 9 && nb >= 0)
		len += ft_putchar(nb + '0');
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		len += ft_putchar('-');
		len += ft_printnbr(nb * (-1));
	}
	else
	{
		len += ft_printnbr(nb / 10);
		len += ft_printnbr(nb % 10);
	}
	return (len);
}
