/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:05:38 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 20:32:37 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		print_err(char *err_m)
{
	printf("Error\n %s\n", err_m);
	return (-1);
}

int		arg_check(t_d *d, int argc, char **argv)
{
	int i;

	if (argc < 2 || argc >= 4)
		return (print_err(strerror(22)));
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (ft_strncmp(argv[1] + i - 4, ".cub", 4) || i < 5)
		return (print_err("Wrong file format!"));
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) == 0)
			d->bmpflag = 1;
		else
			return (print_err("Wrong option!"));
	}
	return (0);
}

void	mlx_set(t_d *d)
{
	if (d->bmpflag == 0)
		d->win = mlx_new_window(d->mlx, d->w_w, d->w_h, "seuyu");
	d->img.ptr = mlx_new_image(d->mlx, d->w_w, d->w_h);
	d->img.data = (int *)mlx_get_data_addr(d->img.ptr, &d->img.bpp,
	&d->img.size_l, &d->img.endian);
}

void	info_set(t_d *d)
{
	data_init(d);
	d->mlx = mlx_init();
	mlx_get_screen_size(d->mlx, &d->scr_x, &d->scr_y);
}

int		main(int argc, char **argv)
{
	t_d d;

	info_set(&d);
	if (-1 == arg_check(&d, argc, argv))
		exit(-1);
	if (-1 == cub3d_pars(&d, argv) || -1 == valid_map(&d))
		exit(-1);
	buff_init(&d);
	tex_init(&d);
	if (-1 == load_tex(&d))
		exit(-1);
	mlx_set(&d);
	mlx_loop_hook(d.mlx, &main_loop, &d);
	if (d.bmpflag == 0)
	{
		mlx_hook(d.win, KEY_EVENT_PRESS, 0, &key_press, &d);
		mlx_hook(d.win, KEY_EVENT_RELEASE, 0, &key_release, &d);
	}
	mlx_loop(d.mlx);
	if (d.bmpflag == 0)
		mlx_clear_window(d.mlx, d.win);
}
