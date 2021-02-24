/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:47:33 by seuyu             #+#    #+#             */
/*   Updated: 2020/07/20 21:34:59 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*strsrc;
	unsigned char	*strdst;

	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dest;
	i = 0;
	while (i < len)
	{
		strdst[i] = strsrc[i];
		if (strsrc[i] == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
