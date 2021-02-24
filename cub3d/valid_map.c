/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:35:21 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 19:09:55 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_sp(t_d *d)
{
	int i;
	int j;

	i = -1;
	while (d->map[++i])
	{
		j = -1;
		while (d->map[i][++j])
		{
			if (d->map[i][j] == '2')
				(d->sp_num)++;
		}
	}
	if (!(d->sprite = (t_sprite *)malloc(sizeof(t_sprite) * (d->sp_num + 1))))
		return (0);
	return (d->sp_num);
}

void	pars_dir(t_d *d, int i, int j)
{
	if (d->map[i][j] == 'N')
	{
		d->dir[1] = -1;
		d->plane[0] = 0.66;
	}
	else if (d->map[i][j] == 'S')
	{
		d->dir[1] = 1;
		d->plane[0] = -0.66;
	}
	else if (d->map[i][j] == 'W')
	{
		d->dir[0] = -1;
		d->plane[1] = -0.66;
	}
	else if (d->map[i][j] == 'E')
	{
		d->dir[0] = 1;
		d->plane[1] = 0.66;
	}
	d->pos[0] = j + 0.5;
	d->pos[1] = i + 0.5;
	d->nswe_flag = 1;
}

int		diff_map_len(t_d *d, int i)
{
	int		a_len;
	int		b_len;
	int		tmp;

	a_len = ft_strlen(d->map[i]);
	b_len = ft_strlen(d->map[i + 1]);
	tmp = a_len;
	while (tmp < b_len)
	{
		if (d->map[i + 1][tmp] != '1' && d->map[i + 1][tmp] != ' ')
			return (-1);
		tmp++;
	}
	while (a_len > b_len)
	{
		if (d->map[i][b_len] != '1' && d->map[i][b_len] != ' ')
			return (-1);
		b_len++;
	}
	return (1);
}

int		check_zero(t_d *d, int i, int j, int *tmp)
{
	if (d->map[i][j] == '0' || d->map[i][j] == '2'
		|| (is_nswe(d->map[i][j])))
	{
		if (is_nswe(d->map[i][j]))
		{
			if (d->nswe_flag == 1)
				return (-1);
			pars_dir(d, i, j);
		}
		else if (d->map[i][j] == '2')
		{
			d->sprite[*tmp].x = j + 0.5;
			d->sprite[*tmp].y = i + 0.5;
			(*tmp)--;
		}
		if (j == 0 || i == 0 || i == d->map_idx
		|| d->map[i - 1][j] == ' ' || d->map[i + 1][j] == ' '
		|| d->map[i][j - 1] == ' ' || d->map[i][j + 1] == '\0'
		|| d->map[i][j + 1] == ' ')
			return (-1);
	}
	return (1);
}

int		valid_map(t_d *d)
{
	int		i;
	int		j;
	int		tmp;

	tmp = count_sp(d) - 1;
	i = -1;
	while (d->map[++i])
	{
		if (-1 == diff_map_len(d, i))
			return (print_err("invalid map!"));
		j = -1;
		while (d->map[i][++j])
		{
			if (-1 == check_zero(d, i, j, &tmp))
				return (print_err("invalid map!"));
		}
	}
	if (d->nswe_flag == 0)
		return (print_err("invalid map!"));
	return (1);
}
