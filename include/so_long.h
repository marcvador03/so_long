/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 16:31:23 by mfleury          ###   ########.fr       */
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
	//bool			enabled; //used ?
	mlx_image_t		**img;
}	t_anim;

typedef struct s_img_cat
{
	t_sprite	*s_wall;
	t_sprite	*s_item_c;
	t_sprite	*s_exit;
	t_sprite	*s_bckg;
	t_sprite	*s_hero_idle;
	t_sprite	*sm_hero_idle;
	t_sprite	*s_hero_dead;
	t_sprite	*sm_hero_dead;
	t_sprite	*s_item_o;
	t_sprite	*s_mush;
	t_sprite	*s_mons;
	t_sprite	*s_mons_dead;
	t_sprite	*s_arrow_up;
	t_sprite	*s_arrow_down;
	t_sprite	*s_arrow_r;
	t_sprite	*s_arrow_l;
	t_anim		*wall;
	t_anim		*item_c;
	t_anim		*exit;
	t_anim		*bckg;
	t_anim		*hero_idle;
	t_anim		*hero_idle_m;
	t_anim		*hero_dead;
	t_anim		*hero_dead_m;
	t_anim		*item_o;
	t_anim		*mush;
	t_anim		*mons;
	t_anim		*mons_dead;
	t_anim		*arrow_up;
	t_anim		*arrow_down;
	t_anim		*arrow_r;
	t_anim		*arrow_l;
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

/*typedef struct	s_hero // used??
{
	mlx_image_t	**img;
	size_t	instance;
	size_t	count_img; //to be updated
	u_int32_t	w_hero;
	u_int32_t	h_hero;
} t_hero;
*/
typedef struct	s_win 
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
} t_win;


#endif

