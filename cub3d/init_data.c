/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:52:51 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/21 17:17:05 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_init(t_d *d)
{
	d->key_w = 0;
	d->key_s = 0;
	d->key_a = 0;
	d->key_d = 0;
	d->key_l = 0;
	d->key_r = 0;
	d->key_esc = 0;
	d->key_flag_ws = 0;
	d->key_flag_ad = 0;
	d->key_flag_lr = 0;
}

void	pars_init(t_d *d)
{
	int i;

	i = -1;
	while (++i < 8)
		d->e_f[i] = 0;
	d->map_idx = 0;
	d->sp_num = 0;
	d->tex_path[0] = NULL;
	d->tex_path[1] = NULL;
	d->tex_path[2] = NULL;
	d->tex_path[3] = NULL;
	d->tex_path[4] = NULL;
	d->ceil_clr = -1;
	d->floor_clr = -1;
	d->m_start = 0;
}

void	data_init(t_d *d)
{
	d->w_w = -1;
	d->w_h = -1;
	d->rot = 0.05;
	d->m_speed = 0.05;
	d->dir[0] = 0;
	d->dir[1] = 0;
	d->plane[0] = 0;
	d->plane[1] = 0;
	d->bmpflag = 0;
	d->nswe_flag = 0;
	d->t_w = 64;
	d->t_h = 64;
	pars_init(d);
	key_init(d);
}

void	buff_init(t_d *d)
{
	int i;
	int j;

	if (!(d->buf = (int **)malloc(sizeof(int *) * d->w_h + 1)))
		return ;
	i = -1;
	while (++i < d->w_h)
	{
		if (!(d->buf[i] = (int *)malloc(sizeof(int) * d->w_w + 1)))
			return ;
	}
	i = -1;
	while (++i < d->w_h)
	{
		j = -1;
		while (++j < d->w_w)
			d->buf[i][j] = 0;
	}
}

void	tex_init(t_d *d)
{
	int i;
	int j;

	if (!(d->texture = (int **)malloc(sizeof(int*) * 5)))
		return ;
	i = -1;
	while (++i < 5)
	{
		if (!(d->texture[i] = (int *)malloc(sizeof(int) * d->t_w * d->t_h)))
			return ;
	}
	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < d->t_w * d->t_h)
			d->texture[i][j] = 0;
	}
}
