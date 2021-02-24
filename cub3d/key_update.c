/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:16:36 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/21 17:12:47 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_update_ws(t_d *d)
{
	if (d->key_w)
	{
		if (d->map[(int)(d->pos[1])][(int)(d->pos[0] +
		d->dir[0] * d->m_speed)] != '1')
			d->pos[0] += d->dir[0] * d->m_speed;
		if (d->map[(int)(d->pos[1] + d->dir[1] * d->m_speed)]
		[(int)(d->pos[0])] != '1')
			d->pos[1] += d->dir[1] * d->m_speed;
	}
	if (d->key_s)
	{
		if (d->map[(int)(d->pos[1])][(int)(d->pos[0] - d->dir[0] *
		d->m_speed)] != '1')
			d->pos[0] -= d->dir[0] * d->m_speed;
		if (d->map[(int)(d->pos[1] - d->dir[1] * d->m_speed)]
		[(int)(d->pos[0])] != '1')
			d->pos[1] -= d->dir[1] * d->m_speed;
	}
	if (d->key_esc)
		exit(0);
}

void	key_update_ad(t_d *d)
{
	if (d->key_d)
	{
		if (d->map[(int)(d->pos[1])][(int)(d->pos[0] -
		d->dir[1] * d->m_speed)] != '1')
			d->pos[0] -= d->dir[1] * d->m_speed;
		if (d->map[(int)(d->pos[1] + d->dir[0] * d->m_speed)]
		[(int)(d->pos[0])] != '1')
			d->pos[1] += d->dir[0] * d->m_speed;
	}
	if (d->key_a)
	{
		if (d->map[(int)(d->pos[1])][(int)(d->pos[0] + d->dir[1] *
		d->m_speed)] != '1')
			d->pos[0] += d->dir[1] * d->m_speed;
		if (d->map[(int)(d->pos[1] - d->dir[0] * d->m_speed)]
		[(int)(d->pos[0])] != '1')
			d->pos[1] -= d->dir[0] * d->m_speed;
	}
}

void	key_update(t_d *d)
{
	double	tmp_x;
	double	tmp_p_x;

	if (d->key_l)
	{
		tmp_x = d->dir[0];
		d->dir[0] = d->dir[0] * cos(-d->rot) - d->dir[1] * sin(-d->rot);
		d->dir[1] = tmp_x * sin(-d->rot) + d->dir[1] * cos(-d->rot);
		tmp_p_x = d->plane[0];
		d->plane[0] = d->plane[0] * cos(-d->rot) - d->plane[1] * sin(-d->rot);
		d->plane[1] = tmp_p_x * sin(-d->rot) + d->plane[1] * cos(-d->rot);
	}
	if (d->key_r)
	{
		tmp_x = d->dir[0];
		d->dir[0] = d->dir[0] * cos(d->rot) - d->dir[1] * sin(d->rot);
		d->dir[1] = tmp_x * sin(d->rot) + d->dir[1] * cos(d->rot);
		tmp_p_x = d->plane[0];
		d->plane[0] = d->plane[0] * cos(d->rot) - d->plane[1] * sin(d->rot);
		d->plane[1] = tmp_p_x * sin(d->rot) + d->plane[1] * cos(d->rot);
	}
	key_update_ws(d);
	key_update_ad(d);
}
