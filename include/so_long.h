/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/25 10:28:09 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/getnextline/get_next_line.h"
# include "textures.h"
# include "animations.h"
# include "errors.h"
# define BPP 4
# define MOVE 4
# define H 0
# define W 1
# define X 0
# define Y 1
# define XBIS 2
# define YBIS 3
//#include "../MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_list_cleanup
{
	t_sprite	*sprite;
	t_anim		*anim;
}	t_clean;

typedef struct	s_map
{
	char	c;
	mlx_image_t	**img;
	size_t	instance;
} t_map;

typedef struct	s_mainwindow 
{
	int				fd;
	t_map			**map;
	mlx_t			*slx;
	mlx_image_t		*hero;
	mlx_image_t		*wall;
	mlx_image_t		*item;
	mlx_image_t		*exit;
	mlx_image_t		*bckg;
	int32_t			h_win;
	int32_t			w_win;
	u_int32_t		h_map;
	u_int32_t		w_map;
	unsigned int	item_cnt;
	unsigned int	move_cnt;	
	u_int32_t		mem_count;
	t_anim			*hero_idle;
	t_anim			*hero_run;
} t_mainwindow;

void	unexpected_close(char *str, t_mainwindow *sl, t_map **map);
void	exp_close(void *ptr);
mlx_image_t	*load_texture(mlx_t sl, mlx_texture_t *t, t_sprite in);
//void	sl_load_image(t_mainwindow sl);
void	load_static_image(t_mainwindow *sl);
void	load_dynamic_image(t_mainwindow sl, t_sprite *sprite);
void	sl_keyhook(mlx_key_data_t keydata, void *param);

/*map generation functions*/
int		sl_map_check_dups(t_map **map, unsigned int w, unsigned int h);
int		sl_map_check_walls(t_map **map, unsigned int w, unsigned int h);
void	sl_map_fill(t_mainwindow *sl, char *path);
void	get_map_size(t_mainwindow *sl, char *path);
void	map_alloc(t_mainwindow *sl);

/*animation functions*/
t_sprite 	*create_sprite(mlx_texture_t *t, t_sprite in);
t_anim		*create_anime(double fps, int32_t x_move, int32_t y_move);
void	anime_sprite(void *ptr);

		
/*int	create_rgba(int r, int g, int b, int a);
int	get_r(int rgba);
int	get_g(int rgba);
int get_b(int rgba);
int	get_a(int rgba);
int	add_shade(int color, double d);
int	get_neg_color(int color);*/
#endif

