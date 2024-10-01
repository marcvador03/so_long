/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/01 10:31:45 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	image_load_sequence(t_win *sl, t_cat *cat)
{
	load_dynamic_image(sl, cat->bckg, cat->s_bckg, '0');
	load_dynamic_image(sl, cat->item, cat->s_item, 'C');
	load_dynamic_image(sl, cat->wall, cat->s_wall, '1');
	load_dynamic_image(sl, cat->hero, cat->s_hero, 'P');
	load_dynamic_image(sl, cat->exit, cat->s_exit, 'E');
	sl->str_move = mlx_put_string(sl->mlx, "Movements :", 0, 0);
}

static void	texture_load_sequence(t_win *sl, t_cat *cat)
{
	cat->s_bckg = create_sprite(mlx_load_png(BCKG), g_bckg);
	cat->s_item = create_sprite(mlx_load_png(CHEST), g_chest);
	cat->s_hero = create_sprite(mlx_load_png(HERO), g_hero);
	cat->s_wall = create_sprite(mlx_load_png(WALL), g_wall);
	cat->s_exit = create_sprite(mlx_load_png(EXIT), g_exit);
//  NULL condition check. Within create_sprite or here
	if (cat->s_bckg == NULL)
		unexpected_close(ERR_SPRITE, sl, sl->map);
	cat->bckg = create_anime(0, 0, 0, 0, "bckg");
	cat->item = create_anime(0, 0, 0, 2, "item");
	cat->hero = create_anime(0, 0, 0, 3, "hero");
	cat->wall = create_anime(0, 0, 0, 1, "wall");
	cat->exit = create_anime(0, 0, 0, 2, "exit");
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
	///activate(sl.cat->h_idle, 0);
	mlx_close_hook(sl.mlx, &exp_close, &sl);
	mlx_key_hook(sl.mlx, &keyhook, &sl);
	//manage NULL value for hooks parameters
	//mlx_loop_hook(sl.mlx, anime_sprite, sl.cat->h_idle_m);
	//mlx_loop_hook(sl.mlx, anime_sprite, sl.cat->h_run);
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	return (0);
}
