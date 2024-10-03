/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 10:48:28 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	image_load_sequence(t_win *sl, t_cat *cat)
{
	load_image_init(sl, cat->bckg, cat->s_bckg, '0');
	load_image_init(sl, cat->item_c, cat->s_item_c, 'C');
	load_image_init(sl, cat->wall, cat->s_wall, '1');
	load_image_init(sl, cat->exit, cat->s_exit, 'E');
	load_image_init(sl, cat->item_o, cat->s_item_o, 'C');
	load_image_init(sl, cat->mush, cat->s_mush, 'C');
	load_image_init(sl, cat->hero_idle, cat->s_hero_idle, 'P');
	load_image_init(sl, cat->hero_idle_m, cat->sm_hero_idle, 'P');
	load_image_init(sl, cat->hero_dead, cat->s_hero_dead, 'P');
	load_image_init(sl, cat->hero_dead_m, cat->sm_hero_dead, 'P');
	load_image_init(sl, cat->mons, cat->s_mons, 'M');
	load_image_init(sl, cat->mons_dead, cat->s_mons_dead, 'M');
	load_image_init(sl, cat->arrow_up, cat->s_arrow_up, 'P');
	load_image_init(sl, cat->arrow_down, cat->s_arrow_down, 'P');
	load_image_init(sl, cat->arrow_r, cat->s_arrow_r, 'P');
	load_image_init(sl, cat->arrow_l, cat->s_arrow_l, 'P');
	sl->str_move = mlx_put_string(sl->mlx, "Movements :", 0, 0);
}

static void	texture_load_sequence(t_win *sl, t_cat *cat)
{
	cat->s_bckg = create_sprite(mlx_load_png(BCKG), g_bckg);
	cat->s_item_c = create_sprite(mlx_load_png(CHEST_C), g_chest_c);
	cat->s_wall = create_sprite(mlx_load_png(WALL), g_wall);
	cat->s_exit = create_sprite(mlx_load_png(EXIT), g_exit);
	cat->s_item_o = create_sprite(mlx_load_png(CHEST_O), g_chest_o);
	cat->s_mush = create_sprite(mlx_load_png(MUSH), g_mush);
	cat->s_hero_idle = create_sprite(mlx_load_png(HERO_IDLE), g_hero_idle);
	cat->s_hero_dead = create_sprite(mlx_load_png(HERO_DEAD), g_hero_dead);
	cat->sm_hero_idle = create_sprite_m(mlx_load_png(HERO_IDLE), g_hero_idle);
	cat->sm_hero_dead = create_sprite_m(mlx_load_png(HERO_DEAD), g_hero_dead);
	cat->s_mons = create_sprite(mlx_load_png(MONS), g_mons);
	cat->s_mons_dead = create_sprite(mlx_load_png(MONS_DEAD), g_mons_dead);
	cat->s_arrow_down = create_sprite(mlx_load_png(ARROW_UP), g_arrow_up);
	cat->s_arrow_up = create_sprite(mlx_load_png(ARROW_UP), g_arrow_up);
	cat->s_arrow_r = create_sprite(mlx_load_png(ARROW_R), g_arrow_r);
	cat->s_arrow_l = create_sprite_m(mlx_load_png(ARROW_R), g_arrow_r);
//  NULL condition check. Within create_sprite or here
	if (cat->s_bckg == NULL)
		unexpected_close(ERR_SPRITE, sl, sl->map);
	cat->bckg = create_anime(0, 0, "bckg");
	cat->item_c = create_anime(0, 2, "item_c");
	cat->wall = create_anime(0, 1, "wall");
	cat->exit = create_anime(0, 2, "exit");
	cat->item_o = create_anime(0, 2, "item_o");
	cat->mush = create_anime(0.5, 3, "mush");
	cat->hero_idle = create_anime(100, 4, "hero_idle");
	cat->hero_idle_m = create_anime(100, 4, "hero_idle_m");
	cat->hero_dead = create_anime(100, 4, "hero_dead");
	cat->hero_dead_m = create_anime(100, 4, "hero_dead_m");
	cat->mons = create_anime(200, 3, "mons");
	cat->mons_dead = create_anime(300, 3, "mons_dead");
	cat->arrow_up = create_anime(0, 3, "arrow_up");
	cat->arrow_down = create_anime(0, 3, "arrow_down");
	cat->arrow_r = create_anime(0, 3, "arrow_r");
	cat->arrow_l = create_anime(0, 3, "arrow_l");
		//unexpected_close(ERR_ANIME, sl, sl->map);
}

static void	window_init(t_win *sl)
{
	sl->cat = (t_cat *)ft_calloc(sizeof(t_cat), 1);
	if (sl->cat == NULL)
		unexpected_close(ERR_MALLOC, sl, sl->map);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	sl->mlx = mlx_init(sl->w_map * PPT, sl->h_map * PPT, TITLE, true);
	if (sl->mlx == NULL)
		unexpected_close(ERR_MALLOC, sl, sl->map);
}

static void	map_sequence(t_win *sl, char *path)
{
	int32_t h_win;
	int32_t w_win;
	
	mlx_get_monitor_size(0, &w_win, &h_win);
	sl->mlx = NULL;
	sl->dir = 'R';
	sl->move_cnt = 0;
	get_map_size(sl, path);
	map_alloc(sl);
	sl_map_fill(sl, path);
	if (w_win < (sl->w_map * PPT) || h_win < (sl->h_map * PPT))
		unexpected_close(ERR_MAP_SIZE, sl, sl->map);
	if (map_check_walls(sl->map, sl->w_map - 1, sl->h_map - 1) == -1)
		unexpected_close(ERR_MAP_WALLS, sl, sl->map);
	check_path_init(sl, sl->map);
}

int	main(int argc, char *argv[])
{
	t_win	sl;

	if (argc != 2)
		unexpected_close(ERR_MISS_ARG, &sl, NULL);
	map_sequence(&sl, argv[1]);
	window_init(&sl);
	texture_load_sequence(&sl, sl.cat);
	image_load_sequence(&sl, sl.cat);
	mlx_close_hook(sl.mlx, &exp_close, &sl);
	mlx_key_hook(sl.mlx, &keyhook, &sl);
	mlx_loop_hook(sl.mlx, hook_mush, &sl);
	mlx_loop_hook(sl.mlx, hook_weapon, &sl);
	mlx_loop_hook(sl.mlx, hook_idle, &sl);
	mlx_loop_hook(sl.mlx, hook_mons, &sl);
	mlx_loop_hook(sl.mlx, hook_mons_dead, &sl);
	//manage NULL value for hooks parameters
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	return (0);
}
