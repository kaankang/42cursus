/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:23:09 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/30 18:23:13 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	int		byte;
	char	*str;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	byte = 1;
	while (ft_strchr(buffer) && byte != 0)
	{
		byte = read(fd, str, BUFFER_SIZE);
		if (byte == -1)
		{
			free(str);
			return (0);
		}
		str[byte] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (0);
	return (buffer);
}
