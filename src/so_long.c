/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 12:58:15 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	image_load_sequence(t_win *sl, t_cat *cat)
{
	cat->h_idle = create_anime(0.5, 0, 0);
	/*cat->h_run = create_anime(0, 0, 0);
	cat->h_dead = create_anime(0.5, 0, 0);
	if (cat->h_idle == NULL || cat->h_run == NULL || cat->h_dead == NULL)
		unexpected_close(ERR_ANIME, sl, sl->map);*/
	load_static_image(sl, cat);
	load_dynamic_image(*sl, cat->h_idle, cat->h_idle_s);
	/*load_dynamic_image(*sl, cat->h_run, cat->h_run_s);*/
}

static void	texture_load_sequence(t_win *sl, t_cat *cat)
{
	cat->wall = NULL;
	cat->item = NULL;
	cat->bckg = NULL;
	cat->exit = NULL;
	cat->bckg = load_texture(*sl->mlx, mlx_load_png(BCKG), g_bckg);
	cat->wall = load_texture_mirror(*sl->mlx, mlx_load_png(WALL), g_wall);
	cat->item = load_texture_mirror(*sl->mlx, mlx_load_png(CHEST), g_chest);
	if (cat->bckg == NULL || cat->wall == NULL || cat->item == NULL)
		unexpected_close(ERR_LOAD_TEXTURE, sl, sl->map);
	cat->h_idle_s = create_sprite(mlx_load_png(HERO_IDLE), g_hero_idle);
	/*cat->h_run_s = create_sprite(mlx_load_png(HERO_RUN), g_hero_run);
	cat->h_dead_s = create_sprite(mlx_load_png(HERO_DEAD), g_hero_dead);
	if (cat->h_idle_s == NULL || cat->h_run_s == NULL || cat->h_dead_s == NULL)
		unexpected_close(ERR_SPRITE, sl, sl->map);*/
}

static void	window_init(t_win *sl)
{
	sl->cat = (t_cat *)malloc(sizeof(t_cat));
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
	activate(sl.cat->h_idle, 0);
	mlx_close_hook(sl.mlx, &exp_close, &sl);
	mlx_key_hook(sl.mlx, &sl_keyhook, &sl);
	//manage NULL value for hooks parameters
	//mlx_loop_hook(sl.mlx, anime_sprite, sl.cat->h_idle_m);
	//mlx_loop_hook(sl.mlx, anime_sprite, sl.cat->h_run);
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	//free_img(sl.cat);
	return (0);
}
