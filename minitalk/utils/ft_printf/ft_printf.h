/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:02:04 by kkanig            #+#    #+#             */
/*   Updated: 2022/12/25 17:28:00 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printstr(char *str);
int	ft_putchar(char c);
int	ft_printnbr(int nb);
int	ft_u(unsigned int u);
int	ft_print_hex(unsigned int x, int b);
int	ft_print_ptr(unsigned long p);
int	ft_atoi(const char *str);

#endif
