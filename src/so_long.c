/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/02 10:49:12 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	image_load_sequence(t_win *sl, t_cat *cat)
{
	load_image_init(sl, cat->bckg, cat->s_bckg, '0');
	load_image_init(sl, cat->item_c, cat->s_item_c, 'C');
	load_image_init(sl, cat->wall, cat->s_wall, '1');
	load_image_init(sl, cat->hero, cat->s_hero, 'P');
	load_image_init(sl, cat->hero_m, cat->sm_hero, 'P');
	load_image_init(sl, cat->exit, cat->s_exit, 'E');
	load_image_init(sl, cat->item_o, cat->s_item_o, 'C');
	load_image_init(sl, cat->mush, cat->s_mush, 'C');
	//load_image_init(sl, cat->hero_idle, cat->s_hero_idle, 'P');
	//load_image_init(sl, cat->hero_idle_m, cat->sm_hero_idle, 'P');
	load_image_init(sl, cat->hero_run, cat->s_hero_run, 'P');
	load_image_init(sl, cat->hero_run_m, cat->sm_hero_run, 'P');
	load_image_init(sl, cat->hero_dead, cat->s_hero_dead, 'P');
	load_image_init(sl, cat->hero_dead_m, cat->sm_hero_dead, 'P');
	load_image_init(sl, cat->mons, cat->s_mons, 'M');
	load_image_init(sl, cat->mons_dead, cat->s_mons_dead, 'M');
	sl->str_move = mlx_put_string(sl->mlx, "Movements :", 0, 0);
}

static void	texture_load_sequence(t_win *sl, t_cat *cat)
{
	cat->s_bckg = create_sprite(mlx_load_png(BCKG), g_bckg);
	cat->s_item_c = create_sprite(mlx_load_png(CHEST_C), g_chest_c);
	cat->s_hero = create_sprite(mlx_load_png(HERO), g_hero);
	cat->sm_hero = create_sprite_m(mlx_load_png(HERO), g_hero);
	cat->s_wall = create_sprite(mlx_load_png(WALL), g_wall);
	cat->s_exit = create_sprite(mlx_load_png(EXIT), g_exit);
	cat->s_item_o = create_sprite(mlx_load_png(CHEST_O), g_chest_o);
	cat->s_mush = create_sprite(mlx_load_png(MUSH), g_mush);
	//cat->s_hero_idle = create_sprite(mlx_load_png(HERO_IDLE), g_hero_idle);
	//cat->s_hero_run = create_sprite(mlx_load_png(HERO_RUN), g_hero_run);
	cat->s_hero_dead = create_sprite(mlx_load_png(HERO_DEAD), g_hero_dead);
	cat->sm_hero_idle = create_sprite_m(mlx_load_png(HERO_IDLE), g_hero_idle);
	cat->sm_hero_run = create_sprite_m(mlx_load_png(HERO_RUN), g_hero_run);
	cat->sm_hero_dead = create_sprite_m(mlx_load_png(HERO_DEAD), g_hero_dead);
	cat->s_mons = create_sprite(mlx_load_png(MONS), g_mons);
	cat->s_mons_dead = create_sprite(mlx_load_png(MONS_DEAD), g_mons_dead);
//  NULL condition check. Within create_sprite or here
	if (cat->s_bckg == NULL)
		unexpected_close(ERR_SPRITE, sl, sl->map);
	cat->bckg = create_anime(0, 0, "bckg");
	cat->item_c = create_anime(0, 2, "item_c");
	cat->hero = create_anime(0, 4, "hero");
	cat->hero_m = create_anime(0, 4, "hero_m");
	cat->wall = create_anime(0, 1, "wall");
	cat->exit = create_anime(0, 2, "exit");
	cat->item_o = create_anime(0, 2, "item_o");
	cat->mush = create_anime(0.5, 3, "mush");
	//cat->hero_idle = create_anime(0.5, 4, "hero_idle");
	//cat->hero_idle_m = create_anime(0.5, 4, "hero_idle_m");
	cat->hero_run = create_anime(0, 4, "hero_run");
	cat->hero_run_m = create_anime(0, 4, "hero_run_m");
	cat->hero_dead = create_anime(0, 4, "hero_dead");
	cat->hero_dead_m = create_anime(0, 4, "hero_dead_m");
	cat->mons = create_anime(0, 3, "mons");
	cat->mons_dead = create_anime(0, 3, "mons_dead");
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
	mlx_get_monitor_size(0, &sl->w_win, &sl->h_win);
}

static void	map_sequence(t_win *sl, char *path)
{
	sl->mlx = NULL;
	sl->dir = 'R';
	sl->move_cnt = 0;
	get_map_size(sl, path);
	map_alloc(sl);
	sl_map_fill(sl, path);
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
	//mlx_loop_hook(sl.mlx, hook_idle, &sl);
	//manage NULL value for hooks parameters
	//mlx_loop_hook(sl.mlx, anime_sprite, sl.cat->h_idle_m);
	//mlx_loop_hook(sl.mlx, anime_sprite, sl.cat->h_run);
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	return (0);
}
