/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:50:17 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 20:16:16 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 32
# define K_ESC 53
# define KEY_EVENT_PRESS 2
# define KEY_EVENT_RELEASE 3
# define KEY_EVENT_EXIT 17
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17
# define KEY_L 124
# define KEY_R 123
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

typedef struct	s_sprite
{
	double		x;
	double		y;
}				t_sprite;

typedef struct	s_img
{
	int			bpp;
	int			size_l;
	int			endian;
	int			img_w;
	int			img_h;
	void		*ptr;
	int			*data;
}				t_img;

typedef struct	s_sp
{
	double		sp_x;
	double		sp_y;
	double		tr_x;
	double		tr_y;
	int			sp_scr_x;
	int			vmove_sc;
	int			sp_h;
	int			sp_w;
	int			start[2];
	int			end[2];
	int			color;
	int			udiv;
	int			vdiv;
	int			vmove;
}				t_sp;

typedef struct	s_c
{
	double		raydir[2];
	int			m_x;
	int			m_y;
	double		d_dist[2];
	double		f_dist[2];
	double		raydist;
	int			side;
	int			step[2];
	int			line_h;
	int			start;
	int			end;
	double		wall_x;
	int			t_x;
	int			t_y;
	double		t_step;
	double		t_pos;
	int			t_num;
}				t_c;

typedef struct	s_d
{
	char		**map;
	int			map_idx;
	int			**buf;
	int			**texture;
	void		*mlx;
	void		*win;
	t_img		img;
	double		pos[2];
	double		dir[2];
	double		plane[2];
	double		m_speed;
	double		rot;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_l;
	int			key_r;
	int			key_esc;
	int			key_flag_ws;
	int			key_flag_ad;
	int			key_flag_lr;
	double		z_buffer[8000];
	int			w_w;
	int			w_h;
	char		*tex_path[5];
	int			ceil_clr;
	int			floor_clr;
	int			sp_num;
	t_sprite	*sprite;
	int			scr_x;
	int			scr_y;
	int			bmpflag;
	int			nswe_flag;
	int			vmove;
	int			t_w;
	int			t_h;
	size_t		map_len;
	int			m_start;
	int			e_f[8];
}				t_d;

int				get_next_line(int fd, char **line);
char			*ft_strdup(char const *s1);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				cub3d_pars(t_d *d, char **argv);
int				check_m_data(t_d *d);
int				map_line_check(char *line);
int				valid_map(t_d *d);
int				pars_map(char *line, t_d *d);
void			draw(t_d *d);
void			draw_bground(t_d *d);
void			draw_wall(t_d *d);
void			rc_sprite(t_d *d);
int				main_loop(t_d *d);
int				load_tex(t_d *d);
void			data_init(t_d *d);
void			buff_init(t_d *d);
void			tex_init(t_d *d);
int				save_bmp(t_d *d);
void			sort_sprite(int *order, double *dist, int amount);
int				pars_color(t_d *d, char *line, char id);
int				is_numstr(char *str);
int				is_nswe(char dir);
int				is_numstr(char *str);
int				print_err(char *err_m);
int				check_p_f(t_d *d, int id);
void			free_split(char **split);
void			key_update(t_d *d);
int				key_press(int key, t_d *d);
int				key_release(int key, t_d *d);

#endif
