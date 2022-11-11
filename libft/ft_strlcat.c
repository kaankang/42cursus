/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:56:15 by kkanig            #+#    #+#             */
/*   Updated: 2022/10/26 15:23:22 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (dstsize < d_len + 1)
		return (dstsize + s_len);
	if (dstsize >= d_len + 1)
	{
		while (src[i] != '\0' && d_len + i < dstsize - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
	}
	dst[d_len + i] = 0;
	return (d_len + s_len);
}
