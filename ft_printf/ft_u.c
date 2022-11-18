/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:28:57 by kkanig            #+#    #+#             */
/*   Updated: 2022/11/16 13:26:59 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int u)
{
	int	len;

	len = 0;
	if (u <= 9)
		len += ft_putchar(u + '0');
	else
	{
		len += ft_u(u / 10);
		len += ft_u(u % 10);
	}
	return (len);
}