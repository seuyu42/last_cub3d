/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 05:06:15 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 20:31:41 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_nswe(char dir)
{
	if (dir == 'N' || dir == 'S' || dir == 'W'
	|| dir == 'E')
		return (1);
	return (0);
}

int		is_numstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		map_line_check(char *line)
{
	while (*line == ' ')
		line++;
	if (line[0] == '1')
		return (1);
	return (0);
}

int		check_p_f(t_d *d, int id)
{
	if (id == 0 && d->e_f[1] == 1)
		return (-1);
	else if (id == 1 && d->e_f[2] == 1)
		return (-1);
	else if (id == 2 && d->e_f[3] == 1)
		return (-1);
	else if (id == 3 && d->e_f[4] == 1)
		return (-1);
	else if (id == 4 && d->e_f[5] == 1)
		return (-1);
	d->e_f[id + 1] = 1;
	return (1);
}

void	free_split(char **split)
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
