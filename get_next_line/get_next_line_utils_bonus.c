/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:17:12 by kkanig            #+#    #+#             */
/*   Updated: 2022/11/20 17:18:24 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *buffer, char *buff)
{
	int		a;
	int		b;
	char	*str;

	a = -1;
	b = 0;
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	if (!buff)
		return (0);
	str = malloc(ft_strlen(buffer) + ft_strlen(buff) + 1);
	if (!str)
		return (0);
	while (buffer[++a] != '\0')
		str[a] = buffer[a];
	while (buff[b] != '\0')
		str[a++] = buff[b++];
	str[a] = '\0';
	free(buffer);
	return (str);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	str = malloc(ft_strlen(buffer) - i + 1);
	i++;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}
