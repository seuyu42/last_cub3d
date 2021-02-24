/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:47:48 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 19:37:30 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprite(t_d *d, int *sp_order, double *sp_dist)
{
	int		i;

	i = -1;
	while (++i < d->sp_num)
	{
		sp_order[i] = i;
		sp_dist[i] = ((d->pos[0] - d->sprite[i].x) * (d->pos[0]\
			- d->sprite[i].x) + (d->pos[1] - d->sprite[i].y) * \
			(d->pos[1] - d->sprite[i].y));
	}
}

void	set_sprite(t_d *d, t_sp *sp, int *sp_order, int i)
{
	double	inv;

	sp->sp_x = d->sprite[sp_order[i]].x - d->pos[0];
	sp->sp_y = d->sprite[sp_order[i]].y - d->pos[1];
	inv = 1.0 / (d->plane[0] * d->dir[1] - d->dir[0] * d->plane[1]);
	sp->tr_x = inv * (d->dir[1] * sp->sp_x - d->dir[0] * sp->sp_y);
	sp->tr_y = inv * (-d->plane[1] * sp->sp_x + d->plane[0] * sp->sp_y);
	sp->sp_scr_x = (int)((d->w_w / 2) * (1 + sp->tr_x / sp->tr_y));
	sp->vmove_sc = (int)(sp->vmove / sp->tr_y);
	sp->sp_h = (int)fabs((d->w_h / sp->tr_y) / sp->vdiv);
	sp->start[1] = -sp->sp_h / 2 + d->w_h / 2 + sp->vmove_sc;
	if (sp->start[1] < 0)
		sp->start[1] = 0;
	sp->end[1] = sp->sp_h / 2 + d->w_h / 2 + sp->vmove_sc;
	if (sp->end[1] >= d->w_h)
		sp->end[1] = d->w_h - 1;
	sp->sp_w = (int)fabs((d->w_w / sp->tr_y) / sp->udiv);
	sp->start[0] = -sp->sp_w / 2 + sp->sp_scr_x;
	if (sp->start[0] < 0)
		sp->start[0] = 0;
	sp->end[0] = sp->sp_w / 2 + sp->sp_scr_x;
	if (sp->end[0] >= d->w_w)
		sp->end[0] = d->w_w - 1;
}

void	draw_sprite(t_d *d, t_sp *sp)
{
	int tmp;
	int y;
	int t_x;
	int t_y;
	int a;

	tmp = sp->start[0] - 1;
	while (++tmp < sp->end[0])
	{
		t_x = (int)(((tmp - (-sp->sp_w / 2 + sp->sp_scr_x)) *
			d->t_w / sp->sp_w));
		if (sp->tr_y > 0 && tmp > 0 && tmp < d->w_w &&
		sp->tr_y < d->z_buffer[tmp])
		{
			y = sp->start[1] - 1;
			while (++y < sp->end[1])
			{
				a = (y - sp->vmove_sc) - (d->w_h / 2) + (sp->sp_h / 2);
				t_y = ((a * d->t_h) / sp->sp_h);
				sp->color = d->texture[4][d->t_w * t_y + t_x];
				if ((sp->color & 0x00FFFFFF) != 0)
					d->buf[y][tmp] = sp->color;
			}
		}
	}
}

void	rc_sprite(t_d *d)
{
	int		i;
	t_sp	sp;
	int		sp_order[d->sp_num];
	double	sp_dist[d->sp_num];

	sp.udiv = 1;
	sp.vdiv = 1;
	sp.vmove = 100;
	init_sprite(d, sp_order, sp_dist);
	sort_sprite(sp_order, sp_dist, d->sp_num);
	i = -1;
	while (++i < d->sp_num)
	{
		set_sprite(d, &sp, sp_order, i);
		draw_sprite(d, &sp);
	}
}
