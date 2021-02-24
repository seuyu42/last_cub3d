/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:18:46 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/21 17:21:43 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press_ws(int key, t_d *d)
{
	if (key == K_ESC)
		exit(0);
	if (key == KEY_W)
	{
		if (d->key_s == 1)
		{
			d->key_flag_ws = 1;
			d->key_s = 0;
		}
		d->key_w = 1;
	}
	if (key == KEY_S)
	{
		if (d->key_w == 1)
		{
			d->key_flag_ws = 2;
			d->key_w = 0;
		}
		d->key_s = 1;
	}
	return (0);
}

int		key_press_ad(int key, t_d *d)
{
	if (key == KEY_A)
	{
		if (d->key_d == 1)
		{
			d->key_flag_ad = 1;
			d->key_d = 0;
		}
		d->key_a = 1;
	}
	if (key == KEY_D)
	{
		if (d->key_a == 1)
		{
			d->key_flag_ad = 2;
			d->key_a = 0;
		}
		d->key_d = 1;
	}
	return (0);
}

int		key_press(int key, t_d *d)
{
	if (key == KEY_L)
	{
		if (d->key_l == 1)
		{
			d->key_flag_lr = 2;
			d->key_l = 0;
		}
		d->key_r = 1;
	}
	if (key == KEY_R)
	{
		if (d->key_r == 1)
		{
			d->key_flag_lr = 1;
			d->key_r = 0;
		}
		d->key_l = 1;
	}
	key_press_ws(key, d);
	key_press_ad(key, d);
	return (0);
}
