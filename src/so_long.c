/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/24 12:22:24 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_close(void *str)
{
		ft_printf("%s", (char *)str);
		exit(1);
}

int	main(int argc, char *argv[])
{
	t_mainwindow	sl;
	//t_sprite		*hero_idle_s;
	int32_t			i;

	if (argc != 2)
		sl_close("missing argument\n");
	get_map_size(&sl, argv[1]);
	sl.map = (t_map **)ft_calloc(sl.h_map, sizeof(t_map *));
	if (sl.map == NULL)
		sl_close("error in calloc map");	
	i = 0;
	while (i <= (sl.h_map))
	{
		sl.map[i++] = (t_map *)ft_calloc(sl.w_map, sizeof(t_map));
		if (sl.map == NULL)
			sl_close("error in calloc map[i]");	
	}
	sl.map[i] = NULL;
	sl_map_fill(&sl, argv[1]);
	sl_map_check_walls(sl.map, sl.w_map - 1, sl.h_map - 1);
	sl_map_check_dups(sl.map, sl.w_map - 1, sl.h_map - 1);
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	sl.slx = mlx_init(sl.w_map * PPT, sl.h_map * PPT, "Test", true);
	if (sl.slx == NULL)
		sl_close("Error");
	mlx_get_monitor_size(0, &sl.w_win, &sl.h_win);
	
	sl.move_cnt = 0;	
	
	sl.wall = NULL; //initialize all sl items to NULL to manage errors
	sl.item = NULL; //initialize all sl items to NULL to manage errors
	sl.bckg = NULL; //initialize all sl items to NULL to manage errors
	sl.bckg = load_texture(*sl.slx, mlx_load_png(BCKG), g_bckg);	
	sl.wall = load_texture(*sl.slx, mlx_load_png(WALL), g_wall);	
	sl.item = load_texture(*sl.slx, mlx_load_png(CHEST), g_chest);	
	//hero_idle_s = create_sprite(mlx_load_png(HERO_IDLE), g_hero_idle);
	//sl.hero_idle = create_anime(0.5, 0, 0);
	//-sl.item = load_texture(*sl.slx, mlx_load_png(CHEST), g_chest);	
	
	load_static_image(sl);
	////load_dynamic_image(sl, hero_idle_s);
	mlx_close_hook(sl.slx, sl_close, "Closing\n");	
	mlx_key_hook(sl.slx, &sl_keyhook, &sl);
	//mlx_loop_hook(sl.slx, anime_sprite, sl.hero_idle);
	mlx_loop(sl.slx);
	sl_close("");
	return (0);
}
