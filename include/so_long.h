/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 23:09:29 by mfleury          ###   ########.fr       */
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
# include "errors.h"
# include "textures.h"
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
# define IMG 2
# define INIT 3
# define PX 4

typedef struct	s_anim
{
	double			fps;
	int32_t			x_move;
	int32_t			y_move;
	size_t			count;
	size_t			frame; //where init??
	int32_t			depth;
	bool			enabled; //used?
	mlx_image_t		**img;
}	t_anim;

typedef struct s_img_cat
{
	t_sprite	*s_wall;
	t_sprite	*s_item;
	t_sprite	*s_exit;
	t_sprite	*s_bckg;
	t_sprite	*s_hero;
	t_anim		*wall;
	t_anim		*item;
	t_anim		*exit;
	t_anim		*bckg;
	t_anim		*hero;
}	t_cat;

typedef struct	s_map
{
	char	c;
	char	v;
	int32_t	x; //used?
	int32_t	y; //used?
	t_anim	*a;
	size_t	cur_img;
	size_t	inst;
	size_t	cnt_a; 
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
	t_hero		*hero; //used?
	u_int32_t	w_hero;
	u_int32_t	h_hero;
	t_cat		*cat;
	u_int32_t	item_cnt;
	u_int32_t	move_cnt;	
	u_int32_t	mem_count; //used?
} t_win;

void	unexpected_close(char *str, t_win *sl, t_map **map);
void	exp_close(void *ptr);
void	free_img(t_cat *cat);
void	load_static_image(t_win *sl, t_cat *cat);
void	load_dynamic_image(t_win *sl, t_anim *a, t_sprite *sprite, char c);
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
t_anim	*create_anime(double fps, int32_t x_move, int32_t y_move, int32_t z);
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
size_t	move_init(t_win *sl, keys_t key, t_map map);
char	check_collision(t_map *map_adj, int32_t hero[4], int32_t move[2]);
size_t	move_hero(t_map **map_adj, int32_t move[2], int32_t hero[4]);
void	collect_item(t_win *sl, t_map **map, t_map a);

#endif

