/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:30:47 by seuyu             #+#    #+#             */
/*   Updated: 2020/07/23 17:20:04 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(char const *src, int size)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(dst = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int		ft_str_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void		ft_freeall(char **split)
{
	size_t i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int		ft_char_count(char **split, char const *s, char c, int num)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (num > 0)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
		{
			s++;
			j++;
		}
		if (!(split[count - 1] = ft_strndup(s - j, j)))
		{
			ft_freeall(split);
			return (0);
		}
		num--;
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	int		strnum;
	char	**split;

	if (!s)
		return (NULL);
	strnum = ft_str_count(s, c);
	if (!(split = (char**)malloc(sizeof(char*) * (strnum + 1))))
		return (NULL);
	split[strnum] = NULL;
	if (!ft_char_count(split, s, c, strnum))
		return (NULL);
	return (split);
}
