/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:53:05 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 19:31:54 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_m_data(t_d *d)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		if (d->e_f[i] == 0)
			return (-1);
	}
	return (1);
}

int		check_m_elem(char *line, t_d *d)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
		&& line[i] != '2' && line[i] != 'N' && line[i] != 'S'
		&& line[i] != 'W' && line[i] != 'E')
			return (-1);
		i++;
	}
	if (!(d->map = (char **)malloc(sizeof(char *) * 2)))
		return (-1);
	d->map[0] = ft_strdup(line);
	d->map[1] = NULL;
	d->map_idx++;
	d->m_start = 1;
	return (1);
}

int		pars_map(char *line, t_d *d)
{
	char	**tmp;
	int		i;

	if (d->map_idx == 0)
	{
		if (-1 == check_m_elem(line, d))
			return (-1);
	}
	else
	{
		tmp = d->map;
		if (!(d->map = (char **)malloc(sizeof(char *) * (d->map_idx + 2))))
			return (-1);
		d->map[d->map_idx] = ft_strdup(line);
		d->map[d->map_idx + 1] = NULL;
		i = d->map_idx;
		while (--i >= 0)
		{
			d->map[i] = ft_strdup(tmp[i]);
			free(tmp[i]);
		}
		free(tmp);
		d->map_idx++;
	}
	return (1);
}
