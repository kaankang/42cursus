/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:11:04 by kkanig            #+#    #+#             */
/*   Updated: 2022/11/20 17:20:35 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char		*line;
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_clean(buffer[fd]);
	return (line);
}
