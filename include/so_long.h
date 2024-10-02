/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/02 09:49:40 by mfleury          ###   ########.fr       */
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
	char			*name;
	double			fps;
	double			time;
	size_t			count;
	int32_t			**frame;
	int32_t			depth;
	bool			enabled; //used ?
	mlx_image_t		**img;
}	t_anim;

typedef struct s_img_cat
{
	t_sprite	*s_wall;
	t_sprite	*s_item_c;
	t_sprite	*s_exit;
	t_sprite	*s_bckg;
	t_sprite	*s_hero;
	t_sprite	*sm_hero;
	t_sprite	*s_hero_idle;
	t_sprite	*sm_hero_idle;
	t_sprite	*s_hero_run;
	t_sprite	*sm_hero_run;
	t_sprite	*s_hero_dead;
	t_sprite	*sm_hero_dead;
	t_sprite	*s_item_o;
	t_sprite	*s_mush;
	t_anim		*wall;
	t_anim		*item_c;
	t_anim		*exit;
	t_anim		*bckg;
	t_anim		*hero;
	t_anim		*hero_m;
	t_anim		*hero_idle;
	t_anim		*hero_idle_m;
	t_anim		*hero_run;
	t_anim		*hero_run_m;
	t_anim		*hero_dead;
	t_anim		*hero_dead_m;
	t_anim		*item_o;
	t_anim		*mush;
}	t_cat;

typedef struct	s_map
{
	char	c;
	char	v;
	int32_t	x; //used?
	int32_t	y; //used?
	//t_anim	**a;
	t_anim	*cur_a;
	size_t	inst;
	size_t	cnt; 
} t_map;

typedef struct	s_hero // used??
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
	int32_t		h_win; // used?
	int32_t		w_win; // used?
	u_int32_t	h_map;
	u_int32_t	w_map;
	u_int32_t	w_hero;
	u_int32_t	h_hero;
	t_cat		*cat;
	u_int32_t	item_cnt;
	u_int32_t	move_cnt;	
	u_int32_t	mem_count; //used?
	mlx_image_t	*str_move;
	mlx_image_t	*s_cnt;
	t_anim		*hero;
	char		dir;
} t_win;

void	unexpected_close(char *str, t_win *sl, t_map **map);
void	exp_close(void *ptr);
void	esc_close(t_win *sl, t_map **map);
void	load_static_image(t_win *sl, t_cat *cat);
void	attach_image(t_map *map, t_anim *a);
void	load_image_init(t_win *sl, t_anim *a, t_sprite *sprite, char c);
void	load_no_attach(t_win *sl, t_anim *a, t_sprite *sprite);
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
t_anim	*create_anime(double fps, int32_t z, char *name);
void	anime_sprite(void *ptr);
void	switch_img(t_map *map, t_anim *out, t_anim *in);
void	activate_anim(t_map *map, t_anim *out, t_anim *in);
void	move_mush(t_win *sl, mlx_image_t *img, int32_t i);
void	hook_mush(void *ptr);
void	hook_idle(void *ptr);
void	anime_hero(t_win *sl); 

/* Sprite and Sprite utils*/
t_sprite 	*create_sprite(mlx_texture_t *t, t_sprite in);
t_sprite 	*create_sprite_m(mlx_texture_t *t, t_sprite in);
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
size_t	move_auth_init(t_win *sl, keys_t key, t_map map);
char	check_collision(t_map *map_adj, int32_t hero[4], int32_t move[2]);
void	collect_item(t_win *sl, t_map **map, t_map a);

#endif

