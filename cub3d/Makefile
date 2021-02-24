# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 16:50:40 by seuyu             #+#    #+#              #
#    Updated: 2021/02/24 17:16:01 by seuyu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D


SRCS = main.c \
		parsing.c \
		ft_cub3d.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		init_data.c \
		save_bmp.c \
		draw.c \
		load_texture.c \
		ft_cal_wall.c \
		ft_cal_sp.c \
		valid_map.c \
		sort_sprite.c \
		pars_map.c \
		pars_color.c \
		pars_tools.c \
		key_update.c \
		key_press.c \
		key_release.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework Appkit -framework OpenGL
MLXPATH = mlx
MLX_A = libmlx.dylib
MLX = mlx/libmlx.dylib
LIBPATH = libft
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
OPTION = -c

.c.o :
	$(CC) $(CFLAGS) $(OPTION) $< -o $@



$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) -L$(MLXPATH) -lmlx $(MLXFLAGS) -L$(LIBPATH) -lft -o $(NAME) $(OBJS)


$(MLX):
	$(MAKE) -C $(MLXPATH)
	cp ./mlx/$(MLX_A) ./

$(LIBFT):
	$(MAKE) -C ./$(LIBPATH)

all : $(NAME)

clean :
	rm -f $(OBJS) $(MLX)
	cd $(MLXPATH); make clean
	cd $(LIBPATH); make clean

fclean : clean
	rm -f $(NAME)
	cd $(LIBPATH); make fclean
	rm -f $(MLX_A)

re : fclean all

.PHONY: all clean fclean re
