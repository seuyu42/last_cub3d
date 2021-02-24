/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:53:11 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 18:11:38 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cal_dist(t_d *d)
{
	draw_wall(d);
	rc_sprite(d);
}

int		window_close(t_d *d)
{
	if (d->bmpflag == 0)
		mlx_destroy_window(d->mlx, d->win);
	exit(0);
	return (0);
}

int		main_loop(t_d *d)
{
	if (d->bmpflag == 0)
		mlx_hook(d->win, 17, 0, window_close, d);
	draw_bground(d);
	cal_dist(d);
	draw(d);
	key_update(d);
	return (0);
}
