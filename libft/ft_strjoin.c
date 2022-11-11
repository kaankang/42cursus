/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:06:59 by kkanig            #+#    #+#             */
/*   Updated: 2022/10/23 17:24:11 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*str;
	size_t	len;

	a = 0;
	i = 0;
	if (s1 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = (char *)malloc(sizeof(char) * (len));
		if (str == NULL)
			return (0);
		while (s1[i] != '\0')
			str[a++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			str[a++] = s2[i++];
		str[a] = '\0';
		return (str);
	}
	return (0);
}
