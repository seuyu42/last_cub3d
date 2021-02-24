/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:17:37 by seuyu             #+#    #+#             */
/*   Updated: 2020/07/20 21:35:08 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*strdst;
	const unsigned char	*strsrc;

	if (!dest && !src)
		return (NULL);
	i = 0;
	strdst = (unsigned char *)dest;
	strsrc = (const unsigned char *)src;
	if (strsrc < strdst)
		while (i < len)
		{
			strdst[len - i - 1] = strsrc[len - i - 1];
			i++;
		}
	else
		while (i < len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	return (dest);
}
