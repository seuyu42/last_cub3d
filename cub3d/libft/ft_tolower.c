/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:51:24 by seuyu             #+#    #+#             */
/*   Updated: 2020/07/20 21:33:33 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c + 32;
	return (c);
}
