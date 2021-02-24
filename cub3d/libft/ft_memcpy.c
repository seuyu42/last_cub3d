/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:17:33 by seuyu             #+#    #+#             */
/*   Updated: 2020/07/20 21:34:53 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*strsrc;
	unsigned char	*strdest;

	if (!dest && !src)
		return (NULL);
	strsrc = (unsigned char *)src;
	strdest = (unsigned char *)dest;
	i = 0;
	while (i < len)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dest);
}
