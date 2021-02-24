/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:53:00 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/21 13:10:39 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_image(t_d *d, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	if (!(img->ptr = mlx_xpm_file_to_image(d->mlx, path, &img->img_w,
	&img->img_h)))
		return (print_err("Wrong texture path or filename!"));
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp,
	&img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			texture[img->img_w * y + x] = img->data[img->img_w * y + x];
	}
	mlx_destroy_image(d->mlx, img->ptr);
	return (0);
}

int	load_tex(t_d *d)
{
	int		i;
	t_img	img;

	i = -1;
	while (++i < 5)
	{
		if (-1 == load_image(d, d->texture[i], d->tex_path[i], &img))
			return (-1);
	}
	return (1);
}
