/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:49:42 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 18:50:00 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cal_init(t_d *d, t_c *c, int x)
{
	double cam_x;

	cam_x = 2 * x / (double)d->w_w - 1;
	c->raydir[0] = d->dir[0] + d->plane[0] * cam_x;
	c->raydir[1] = d->dir[1] + d->plane[1] * cam_x;
	c->m_x = (int)d->pos[0];
	c->m_y = (int)d->pos[1];
	c->d_dist[0] = fabs(1 / c->raydir[0]);
	c->d_dist[1] = fabs(1 / c->raydir[1]);
}

void	cal_firstdist(t_d *d, t_c *c)
{
	if (c->raydir[0] < 0)
	{
		c->step[0] = -1;
		c->f_dist[0] = (d->pos[0] - c->m_x) * c->d_dist[0];
	}
	else
	{
		c->step[0] = 1;
		c->f_dist[0] = (c->m_x + 1.0 - d->pos[0]) * c->d_dist[0];
	}
	if (c->raydir[1] < 0)
	{
		c->step[1] = -1;
		c->f_dist[1] = (d->pos[1] - c->m_y) * c->d_dist[1];
	}
	else
	{
		c->step[1] = 1;
		c->f_dist[1] = (c->m_y + 1.0 - d->pos[1]) * c->d_dist[1];
	}
}

void	cal_wallhit(t_d *d, t_c *c)
{
	while (1)
	{
		if (c->f_dist[0] < c->f_dist[1])
		{
			c->side = 0;
			c->m_x += c->step[0];
			c->f_dist[0] += c->d_dist[0];
		}
		else
		{
			c->side = 1;
			c->m_y += c->step[1];
			c->f_dist[1] += c->d_dist[1];
		}
		if (d->map[c->m_y][c->m_x] == '1')
			break ;
	}
	if (c->side == 0 && c->step[0] == 1)
		c->t_num = 0;
	else if (c->side == 0 && c->step[0] == -1)
		c->t_num = 1;
	else if (c->side == 1 && c->step[1] == -1)
		c->t_num = 3;
	else if (c->side == 1 && c->step[1] == 1)
		c->t_num = 2;
}

void	cal_tex(t_d *d, t_c *c)
{
	double wall_x;

	if (c->side == 1)
		c->raydist = (c->m_y - d->pos[1] + (1 - c->step[1]) / 2) / c->raydir[1];
	else
		c->raydist = (c->m_x - d->pos[0] + (1 - c->step[0]) / 2) / c->raydir[0];
	c->line_h = (int)(d->w_h / c->raydist);
	c->start = -c->line_h / 2 + d->w_h / 2;
	if (c->start < 0)
		c->start = 0;
	c->end = c->line_h / 2 + d->w_h / 2;
	if (c->end >= d->w_h)
		c->end = d->w_h - 1;
	if (c->side == 1)
		wall_x = d->pos[0] + c->raydist * c->raydir[0];
	else
		wall_x = d->pos[1] + c->raydist * c->raydir[1];
	wall_x -= floor(wall_x);
	c->t_x = (int)(wall_x * (double)d->t_w);
	if (c->side == 0 && c->raydir[0] > 0)
		c->t_x = d->t_w - c->t_x - 1;
	if (c->side == 1 && c->raydir[1] < 0)
		c->t_x = d->t_w - c->t_x - 1;
	c->t_step = 1.0 * d->t_h / c->line_h;
	c->t_pos = (c->start - d->w_h / 2 + c->line_h / 2) * c->t_step;
}

void	draw_wall(t_d *d)
{
	int y;
	int color;
	t_c c;
	int x;

	x = -1;
	while (++x < d->w_w)
	{
		cal_init(d, &c, x);
		cal_firstdist(d, &c);
		cal_wallhit(d, &c);
		cal_tex(d, &c);
		y = c.start - 1;
		while (++y < c.end)
		{
			c.t_y = (int)c.t_pos & (d->t_h - 1);
			c.t_pos += c.t_step;
			color = d->texture[c.t_num][c.t_y * d->t_h + c.t_x];
			d->buf[y][x] = color;
		}
		d->z_buffer[x] = c.raydist;
	}
}
