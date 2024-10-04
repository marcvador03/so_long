/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 11:59:41 by mfleury          ###   ########.fr       */
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
# include "collections.h"
# define TITLE "so_long mfleury"
# define BPP 4
# define MOVE 8
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

typedef struct s_map
{
	char	c;
	char	v;
	int32_t	x;
	int32_t	y;
	t_anim	*cur_a;
	size_t	inst;
	size_t	cnt;
}	t_map;

typedef struct s_win
{
	int			fd;
	t_map		**map;
	mlx_t		*mlx;
	u_int32_t	h_map;
	u_int32_t	w_map;
	t_cat		*cat;
	u_int32_t	item_cnt;
	u_int32_t	move_cnt;	
	u_int32_t	map_cnt;
	mlx_image_t	*str_move;
	mlx_image_t	*s_cnt;
	t_anim		*hero;
	char		dir;
}	t_win;

/*Exit and basic functions */
void			unexpected_close(char *str, t_win *sl);
void			esc_close(t_win *sl, t_map **map);
void			free_img(mlx_t *mlx, t_anim *a);
void			free_cat(mlx_t *mlx, t_cat *cat);
void			free_map(t_win *sl);
void			open_file(t_win *sl, char *path);
/* Maps and map checks related functions */
void			get_map_size(t_win *sl, char *path);
void			map_alloc(t_win *sl);
void			map_fill(t_win *sl, char *path);
int32_t			map_len(int32_t move[2], int32_t hero[5]);
void			check_init(t_win *sl, t_map **map);
void			check_path_init(t_win *sl, t_map **map);
void			check_file_ext(t_win *sl, char *path);
void			free_line_err(t_win *sl, char *line, char *error);
/* Animations related functions */
t_anim			*create_anime(t_win *sl, double fps, int32_t z, char *name);
void			switch_img(t_map *map, t_anim *out, t_anim *in);
void			switch_hero(t_anim *out, t_anim *in);
void			switch_direction(t_win *sl, int32_t move[2]);
void			activate_anim(t_map *map, t_anim *out, t_anim *in);
void			update_anim_frame(t_win *sl, t_anim *a);
void			anime_object(t_win *sl, t_anim *a, int32_t i, int max);
/* Physics and movements related functions */
int32_t			*fill_move(t_win *sl, t_anim *a, keys_t key);
int32_t			*fill_coord(t_win *sl, t_anim *a, keys_t key);
t_map			**identify_adj_map(t_win *sl, int32_t *move, int32_t *hero);
size_t			move_auth_init(t_win *sl, keys_t key, t_anim *a);
/* Actions related functions */
void			collect_item(t_win *sl, t_map **map, t_map a);
void			weapon_launch(t_win *sl, keys_t key);
void			kill_monster(t_win *sl, t_map **map_adj, t_anim *a);
void			move_weapon_init(t_win *sl, t_anim *a);
void			move_mush(t_win *sl, mlx_image_t *img, int32_t n);
void			move_init(t_win *sl, keys_t key);
/* Sprite related functions */
t_sprite		*create_sprite(t_win *sl, mlx_texture_t *t, t_sprite in);
void			sprite_init(t_sprite *s, t_sprite in);
t_sprite		*create_sprite_m(t_win *sl, mlx_texture_t *t, t_sprite in);
int				init_var(size_t **cnt, t_sprite **s, t_sprite in);
void			free_sprite(size_t *cnt, t_sprite *s, mlx_texture_t *t);//
void			s_err(t_win *sl, size_t *cnt, t_sprite *s, mlx_texture_t *t);
void			set_var(size_t cnt[5], int32_t *q, t_sprite in, int32_t w);
void			set_q(size_t cnt[5], int32_t *q);
void			set_var_m(size_t cnt[5], int32_t *q, t_sprite in, int32_t w);
/* Textures related functions */
mlx_texture_t	*create_sub_txt(size_t w, size_t h);
mlx_image_t		*load_txt(t_win *sl, mlx_texture_t *t_in, t_sprite in);
mlx_image_t		*load_txt_m(t_win *sl, mlx_texture_t *t_in, t_sprite in);
/* Loading related function */
void			load_img_init(t_win *sl, t_anim *a, t_sprite *sprite, char c);
void			attach_image(t_map *map, t_anim *a);
/* Hook related functions*/
void			hook_mush(void *ptr);
void			hook_weapon(void *ptr);
void			hook_idle(void *ptr);
void			hook_mons_dead(void *ptr);
void			hook_mons(void *ptr);
void			hook_key(mlx_key_data_t k, void *param);
void			hook_close(void *ptr);

#endif
