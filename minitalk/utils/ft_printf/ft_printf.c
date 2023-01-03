/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:04:33 by kkanig            #+#    #+#             */
/*   Updated: 2022/11/16 13:16:47 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findformat(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar('%');
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		len += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_u(va_arg(args, unsigned int));
	else if (c == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		len += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (c == 'p')
	{
		len += ft_printstr("0x");
		len += ft_print_ptr(va_arg(args, unsigned long));
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_findformat(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
