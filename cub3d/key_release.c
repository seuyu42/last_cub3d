/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:52:55 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/21 17:19:27 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_release_ws(int key, t_d *d)
{
	if (key == K_ESC)
		exit(0);
	if (key == KEY_W)
	{
		if (d->key_flag_ws == 1)
			d->key_s = 1;
		else if (d->key_flag_ws == 2)
			d->key_s = 0;
		d->key_flag_ws = 0;
		d->key_w = 0;
	}
	if (key == KEY_S)
	{
		if (d->key_flag_ws == 2)
			d->key_w = 1;
		else if (d->key_flag_ws == 1)
			d->key_w = 0;
		d->key_flag_ws = 0;
		d->key_s = 0;
	}
	return (0);
}

int		key_release_ad(int key, t_d *d)
{
	if (key == KEY_A)
	{
		if (d->key_flag_ad == 1)
			d->key_d = 1;
		else if (d->key_flag_ad == 2)
			d->key_d = 0;
		d->key_flag_ad = 0;
		d->key_a = 0;
	}
	if (key == KEY_D)
	{
		if (d->key_flag_ad == 2)
			d->key_a = 1;
		else if (d->key_flag_ad == 1)
			d->key_a = 0;
		d->key_flag_ad = 0;
		d->key_d = 0;
	}
	return (0);
}

int		key_release(int key, t_d *d)
{
	if (key == KEY_L)
	{
		if (d->key_flag_lr == 2)
			d->key_l = 1;
		else if (d->key_flag_lr == 1)
			d->key_l = 0;
		d->key_flag_lr = 0;
		d->key_r = 0;
	}
	if (key == KEY_R)
	{
		if (d->key_flag_lr == 1)
			d->key_r = 1;
		else if (d->key_flag_lr == 2)
			d->key_r = 0;
		d->key_flag_lr = 0;
		d->key_l = 0;
	}
	key_release_ws(key, d);
	key_release_ad(key, d);
	return (0);
}
