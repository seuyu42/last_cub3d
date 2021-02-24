/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:52:38 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 20:33:38 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_d *d)
{
	int x;
	int y;

	y = -1;
	while (++y < d->w_h)
	{
		x = -1;
		while (++x < d->w_w)
			d->img.data[(d->img).size_l / \
			(d->img.bpp / 8) * y + x] = d->buf[y][x];
	}
	if (d->bmpflag == 1)
	{
		save_bmp(d);
		exit(0);
	}
	else
		mlx_put_image_to_window(d->mlx, d->win, d->img.ptr, 0, 0);
}

void	draw_bground(t_d *d)
{
	int i;
	int j;
	int vert;

	vert = d->w_h / 2;
	i = -1;
	while (++i < d->w_h)
	{
		j = -1;
		while (++j < d->w_w)
		{
			if (i < vert)
				d->buf[i][j] = d->ceil_clr;
			else
				d->buf[i][j] = d->floor_clr;
		}
	}
}
