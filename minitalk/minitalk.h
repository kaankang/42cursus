/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:10:03 by kkanig            #+#    #+#             */
/*   Updated: 2022/12/25 17:42:41 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./utils/ft_printf/ft_printf.h"
# include <signal.h>

void	signal_handler(int sig);
void	function(pid_t pid, char alpha);

#endif
