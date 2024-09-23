/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/24 01:21:37 by mfleury          ###   ########.fr       */
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
	t_sprite		*hero_idle_s;
	t_animation		*hero_idle_a;
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
	
	hero_idle_s = create_sprite(mlx_load_png(HERO_IDLE), g_hero_idle);
	hero_idle_a = create_anime(0.05, 0, 0);
	load_sprite_img(sl, hero_idle_s, hero_idle_a);
	sl.wall = load_texture(*sl.slx, mlx_load_png(WALL), g_wall);	
	/*texture = NULL;
	sl_load_texture(sl, texture, sl.hero, HERO);
	sl_load_texture(sl, texture, sl.item, ITEM);
	sl_load_texture(sl, texture, sl.bckg, BCKG);
	sl_load_texture(sl, texture, sl.wall, WALL);
	sl_load_texture(sl, texture, sl.exit, EXIT);*/
	
	sl_load_image(sl);
	mlx_close_hook(sl.slx, sl_close, "Closing\n");	
	mlx_key_hook(sl.slx, &sl_keyhook, &sl);
	mlx_loop_hook(sl.slx, anime_sprite, hero_idle_a);
	mlx_loop(sl.slx);
	sl_close("");
	return (0);
}
