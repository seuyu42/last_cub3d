/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:58:27 by seuyu             #+#    #+#             */
/*   Updated: 2020/07/21 14:40:34 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_digit(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void			ft_minus(int n, char *str, size_t len)
{
	str[0] = '-';
	str[len] = (n % 10) * -1 + '0';
	n /= 10;
	n *= -1;
	str[len + 1] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

static	void		ft_plus(int n, char *str, size_t len)
{
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char				*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_digit(n);
	if (n >= 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_plus(n, str, len);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * len + 2)))
			return (NULL);
		ft_minus(n, str, len);
	}
	return (str);
}
