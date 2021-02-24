/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:16:44 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 19:24:49 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hex_color(t_d *d, char **split, char id)
{
	int	red;
	int	green;
	int	blue;
	int	ret_color;

	if ((red = ft_atoi(split[0])) > 255 || red < 0)
		return (-1);
	if ((green = ft_atoi(split[1])) > 255 || green < 0)
		return (-1);
	if ((blue = ft_atoi(split[2])) > 255 || blue < 0)
		return (-1);
	ret_color = (red * 16 * 16 * 16 * 16) + (green * 16 * 16) + blue;
	if (id == 'F')
		d->floor_clr = ret_color;
	else if (id == 'C')
		d->ceil_clr = ret_color;
	return (1);
}

int		check_c_f(t_d *d, char id)
{
	if (id == 'F')
	{
		if (d->e_f[6] == 1)
			return (-1);
		d->e_f[6] = 1;
	}
	else if (id == 'C')
	{
		if (d->e_f[7] == 1)
			return (-1);
		d->e_f[7] = 1;
	}
	return (1);
}

int		pars_color(t_d *d, char *line, char id)
{
	char	**split;
	int		i;

	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	i = 0;
	while (split[i])
		i++;
	if (i != 3 || !is_numstr(split[0]) || !is_numstr(split[1]) ||
	!is_numstr(split[2]) || -1 == check_c_f(d, id))
		return (-1);
	if (-1 == hex_color(d, split, id))
		return (-1);
	free_split(split);
	return (1);
}
