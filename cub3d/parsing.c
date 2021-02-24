/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:05:43 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 19:10:49 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		pars_win(t_d *d, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
		i++;
	if (i != 3 || !(is_numstr(split[1])) || !(is_numstr(split[2]))
		|| d->e_f[0] == 1)
		return (-1);
	if (d->scr_x < (d->w_w = ft_atoi(split[1])))
		d->w_w = d->scr_x;
	if (d->scr_y < (d->w_h = ft_atoi(split[2])))
		d->w_h = d->scr_y;
	d->e_f[0] = 1;
	free_split(split);
	if (d->w_w <= 0 || d->w_h <= 0)
		return (-1);
	return (1);
}

int		pars_tex(t_d *d, char *line, int id)
{
	char	**split;
	char	*path;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2 || split[1][0] != '.' || split[1][1] != '/' ||
		-1 == check_p_f(d, id))
		return (-1);
	path = ft_strdup(split[1] + 2);
	if (id == 0)
		d->tex_path[0] = path;
	else if (id == 1)
		d->tex_path[1] = path;
	else if (id == 2)
		d->tex_path[2] = path;
	else if (id == 3)
		d->tex_path[3] = path;
	else if (id == 4)
		d->tex_path[4] = path;
	free_split(split);
	return (1);
}

int		check_id(char *line)
{
	char	**split;
	int		id;

	split = ft_split(line, ' ');
	if (ft_strncmp(split[0], "R", 2) == 0)
		id = 0;
	else if (ft_strncmp(split[0], "EA", 3) == 0)
		id = 1;
	else if (ft_strncmp(split[0], "WE", 3) == 0)
		id = 2;
	else if (ft_strncmp(split[0], "SO", 3) == 0)
		id = 3;
	else if (ft_strncmp(split[0], "NO", 3) == 0)
		id = 4;
	else if (ft_strncmp(split[0], "S", 2) == 0)
		id = 5;
	else if (ft_strncmp(split[0], "C", 2) == 0)
		id = 6;
	else if (ft_strncmp(split[0], "F", 2) == 0)
		id = 7;
	else
		id = -1;
	free_split(split);
	return (id);
}

int		pars_id(char *line, t_d *d)
{
	int		id;

	id = check_id(line);
	if (id == 0)
		return (pars_win(d, line));
	else if (id == 1)
		return (pars_tex(d, line, 0));
	else if (id == 2)
		return (pars_tex(d, line, 1));
	else if (id == 3)
		return (pars_tex(d, line, 2));
	else if (id == 4)
		return (pars_tex(d, line, 3));
	else if (id == 5)
		return (pars_tex(d, line, 4));
	else if (id == 6)
		return (pars_color(d, line, 'C'));
	else if (id == 7)
		return (pars_color(d, line, 'F'));
	else if (id == -1)
		return (-1);
	return (1);
}

int		cub3d_pars(t_d *d, char **argv)
{
	int		fd;
	char	*line;

	if (-1 == (fd = open(argv[1], O_RDONLY)))
		return (print_err(strerror(2)));
	while (get_next_line(fd, &line) > 0)
	{
		if (d->m_start == 1 && line[0] == '\0')
			return (print_err("invalid map!"));
		else if (line[0] != '\0' && !map_line_check(line)
			&& (pars_id(line, d)) == -1)
			return (print_err("invalid map!"));
		else if (map_line_check(line) && (-1 == check_m_data(d)
			|| -1 == pars_map(line, d)))
			return (print_err("invalid map!"));
		free(line);
	}
	free(line);
	return (1);
}
