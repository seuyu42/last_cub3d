/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:53:52 by seuyu             #+#    #+#             */
/*   Updated: 2020/07/21 14:34:45 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 > c2)
			return (c1 - c2);
		else if (c1 < c2)
			return (c1 - c2);
		i++;
	}
	c1 = s1[i];
	c2 = s2[i];
	if (c1 != '\0' && c2 == '\0' && i < n)
		return (c1 - c2);
	else if (c1 == '\0' && c2 != '\0' && i < n)
		return (c1 - c2);
	else
		return (0);
}
