/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:05:47 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/21 04:49:29 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_int_data(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int		bmp_header(int fd, t_d *d)
{
	int				i;
	int				size;
	unsigned char	bmpheader[54];

	size = d->w_w * d->w_h * 4 + 2 + 54;
	i = -1;
	while (++i < 54)
		bmpheader[i] = (unsigned char)(0);
	bmpheader[0] = (unsigned char)('B');
	bmpheader[1] = (unsigned char)('M');
	put_int_data(bmpheader + 2, size);
	bmpheader[10] = (unsigned char)(54);
	bmpheader[14] = (unsigned char)(40);
	put_int_data(bmpheader + 18, d->w_w);
	put_int_data(bmpheader + 22, d->w_h);
	bmpheader[26] = (unsigned char)(1);
	bmpheader[28] = (unsigned char)(32);
	put_int_data(bmpheader + 38, 5000);
	put_int_data(bmpheader + 42, 5000);
	return (!(write(fd, bmpheader, 54) < 0));
}

void	bmp_pixel(int file, t_d *d)
{
	int x;
	int y;
	int color;

	y = d->w_h;
	while (--y >= 0)
	{
		x = -1;
		while (++x < d->w_w)
		{
			color = d->img.data[(d->img).size_l / (d->img.bpp / 8) * y + x];
			write(file, &color, 4);
		}
	}
}

int		save_bmp(t_d *d)
{
	int file;

	if (!(file = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)))
		return (0);
	if (!bmp_header(file, d))
		return (0);
	bmp_pixel(file, d);
	close(file);
	return (1);
}
