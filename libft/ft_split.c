/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:50:37 by kkanig            #+#    #+#             */
/*   Updated: 2022/10/20 14:41:18 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_range(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_copy(char *str, const char *s, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		str[j] = s[i - len];
		len--;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static void	*splitit(char **str, char const *s, char c, int mallocsayi)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (j < mallocsayi)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			len++;
		}
		str[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str[j])
			return (NULL);
		ft_copy (str[j], s, i, len);
		j++;
		len = 0;
	}
	str[j] = NULL;
	return (str[j]);
}

char	**ft_split(char const *s, char c)
{
	int		mallocsayi;
	char	**str;

	if (s != NULL)
	{
		mallocsayi = ft_split_range(s, c);
		str = (char **)malloc(sizeof(char *) * (mallocsayi + 1));
		if (!str)
			return (NULL);
		splitit(str, s, c, mallocsayi);
		return (str);
	}
	return (0);
}
