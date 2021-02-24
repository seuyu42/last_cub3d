/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:39:49 by seuyu             #+#    #+#             */
/*   Updated: 2020/07/20 21:42:16 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	str = (char *)s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
			return (&str[len]);
		len--;
	}
	if (s[len] == (char)c)
		return (str);
	return (NULL);
}
