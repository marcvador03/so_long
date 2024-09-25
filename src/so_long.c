/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/25 17:03:10 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exp_close(void *ptr)
{
	t_mainwindow	*sl;
	size_t	i;

	sl = (t_mainwindow *)ptr;	
	i = 0;
	while (i < sl->mem_count)
		free(sl->map[i++]);	
	free(sl->map);	
}

void	unexpected_close(char *str, t_mainwindow *sl, t_map **map)
{
	size_t	i;

	i = 0;
	if (map != NULL)
	{
		while (i < sl->mem_count)
			free(map[i++]);	
		free(map);	
	}
	ft_printf("%s\n", "Error");
	ft_printf("%s\n", str);
	exit(1); //mlx_terminate??
}

int	main(int argc, char *argv[])
{
	t_mainwindow	sl;
	//t_clean			clean;
	t_sprite		*hero_idle_s;

	sl.slx = NULL;
	if (argc != 2)
		unexpected_close(ERR_MISS_ARG, &sl, NULL);
	get_map_size(&sl, argv[1]);
	map_alloc(&sl);
	sl_map_fill(&sl, argv[1]);
	if (sl_map_check_walls(sl.map, sl.w_map - 1, sl.h_map - 1) == -1)
		unexpected_close(ERR_MAP_FORBID_VALUE, &sl, sl.map);
	if (sl_map_check_dups(sl.map, sl.w_map - 1, sl.h_map - 1) == -1)
		unexpected_close(ERR_MAP_WALLS, &sl, sl.map);
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	sl.slx = mlx_init(sl.w_map * PPT, sl.h_map * PPT, "so_long mfleury", true);
	if (sl.slx == NULL)
		unexpected_close(ERR_MALLOC, &sl, sl.map);
	mlx_get_monitor_size(0, &sl.w_win, &sl.h_win);
	
	sl.move_cnt = 0;	
	
	sl.wall = NULL; //initialize all sl items to NULL to manage errors
	sl.item = NULL; //initialize all sl items to NULL to manage errors
	sl.bckg = NULL; //initialize all sl items to NULL to manage errors*/
	sl.bckg = load_texture(*sl.slx, mlx_load_png(BCKG), g_bckg);
	if (sl.bckg == NULL)
		unexpected_close(ERR_LOAD_TEXTURE, &sl, sl.map);
	sl.wall = load_texture(*sl.slx, mlx_load_png(WALL), g_wall);	
	if (sl.wall == NULL)
		unexpected_close(ERR_LOAD_TEXTURE, &sl, sl.map);
	sl.item = load_texture(*sl.slx, mlx_load_png(CHEST), g_chest);	
	if (sl.item == NULL)
		unexpected_close(ERR_LOAD_TEXTURE, &sl, sl.map);
	sl.hero = load_texture(*sl.slx, mlx_load_png(HERO), g_hero);	
	if (sl.hero == NULL)
		unexpected_close(ERR_LOAD_TEXTURE, &sl, sl.map);
	
	hero_idle_s = create_sprite(mlx_load_png(HERO_IDLE), g_hero_idle);
	if (hero_idle_s == NULL)
		unexpected_close(ERR_SPRITE, &sl, sl.map); // sprite free and sub texture and anime?
	size_t	i;

	i = 0;
	while (i < hero_idle_s->count)
	{
		mlx_delete_texture(hero_idle_s->texture[i++]);
		//free(hero_idle_s->texture[i]->pixels);
		//free(hero_idle_s->texture[i++]);
	}	
	free(hero_idle_s->texture);
	free(hero_idle_s);
	//sl.hero_idle = create_anime(0.5, 0, 0); 
	//if (hero_idle_s == NULL)
	//	unexpected_close(ERR_ANIME, &sl, sl.map); // sprite free and sub texture and anime?
	
	load_static_image(&sl);
	//load_dynamic_image(sl, hero_idle_s);*/
	mlx_close_hook(sl.slx, &exp_close, &sl);	
	mlx_key_hook(sl.slx, &sl_keyhook, &sl);
	//mlx_loop_hook(sl.slx, anime_sprite, sl.hero_idle);
	mlx_loop(sl.slx);
	mlx_terminate(sl.slx);
	return (0);
}
