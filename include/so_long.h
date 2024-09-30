/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 18:48:26 by mfleury          ###   ########.fr       */
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
# define TITLE "so_long mfleury"
# define BPP 4
# define MOVE 4
# define H 0
# define W 1
# define X 0
# define Y 1
# define X_W 2
# define Y_H 3
# define TXT 2
# define INIT 3
# define PX 4
//#include "../MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_img_cat
{
	mlx_image_t	*wall;
	mlx_image_t	*item;
	mlx_image_t	*exit;
	mlx_image_t	*bckg;
	mlx_image_t	*hero;
	mlx_image_t	*m_hero;
		







/*	t_anim			*h_idle;
	t_anim			*h_idle_m;
	t_anim			*h_run;
	t_anim			*h_dead;
	t_sprite		*h_idle_s;
	t_sprite		*h_idle_sm;
	t_sprite		*h_run_s;
	t_sprite		*h_dead_s;*/
}	t_cat;

typedef struct	s_map
{
	char	c;
	char	v;
	int32_t	x;
	int32_t	y;
	mlx_image_t	**img;
	size_t	instance;
	size_t	count_img; //to be updated
} t_map;

typedef struct	s_hero
{
	mlx_image_t	**img;
	size_t	instance;
	size_t	count_img; //to be updated
	u_int32_t	w_hero;
	u_int32_t	h_hero;
} t_hero;

typedef struct	s_win 
{
	int			fd;
	t_map		**map;
	mlx_t		*mlx;
	int32_t		h_win;
	int32_t		w_win;
	u_int32_t	h_map;
	u_int32_t	w_map;
	t_hero		*hero;
	u_int32_t	w_hero;
	u_int32_t	h_hero;
	t_cat		*cat;
	u_int32_t	item_cnt;
	u_int32_t	move_cnt;	
	u_int32_t	mem_count;
} t_win;

void	unexpected_close(char *str, t_win *sl, t_map **map);
void	exp_close(void *ptr);
void	free_img(t_cat *cat);
void	load_static_image(t_win *sl, t_cat *cat);
void	load_dynamic_image(t_win sl, t_anim *a, t_sprite *sprite);
void	activate(t_anim *a, int n);
void	de_activate(t_anim *a, int n);
void	keyhook(mlx_key_data_t keydata, void *param);

/*map generation functions*/
int		map_check_walls(t_map **map, unsigned int w, unsigned int h);
void	check_file_ext(t_win *sl, char *path);
void	sl_map_fill(t_win *sl, char *path);
void	get_map_size(t_win *sl, char *path);
void	map_alloc(t_win *sl);
void	check_path_init(t_win *sl, t_map **map);
int32_t	map_len(int32_t move[2], int32_t hero[4]);

/*animation functions*/
t_anim		*create_anime(double fps, int32_t x_move, int32_t y_move);
void	anime_sprite(void *ptr);

/* Sprite and Sprite utils*/
t_sprite 	*create_sprite(mlx_texture_t *t, t_sprite in);
void	sprite_init(t_sprite *s, t_sprite in);
int		init_var(size_t **cnt, t_sprite **s, t_sprite in);
void	free_sprite(size_t *cnt, t_sprite *s, mlx_texture_t *t);
void	set_q(size_t cnt[5], int32_t *q);
void	set_var(size_t cnt[5], int32_t *q, t_sprite in, int32_t w);
void	set_var_m(size_t cnt[5], int32_t *q, t_sprite in, int32_t w);

/* Texture creation*/
mlx_image_t	*load_texture(mlx_t sl, mlx_texture_t *t, t_sprite in);
mlx_image_t	*load_texture_mirror(mlx_t sl, mlx_texture_t *t, t_sprite in);
mlx_texture_t	*create_sub_txt(size_t w, size_t h);

/*movements functions*/
size_t	move_init(t_win *sl, t_cat *cat, keys_t key, t_map map);
int	check_collision(t_map *map_adj, int32_t hero[4], int32_t move[2]);
size_t	move_hero(t_map **map_adj, t_map map, int32_t move[2], int32_t hero[4]);
void	collect_item(t_win *sl, t_map **map, t_map a)

#endif

