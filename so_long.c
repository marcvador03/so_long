/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/14 12:47:48 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_close(void *str)
{
		ft_printf("%s", (char *)str);
		exit(1);
}

int	main(int argc, char *argv[])
{
	t_mainwindow	sl;
	mlx_texture_t	*texture;
	unsigned int	i;

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
	//mlx_get_monitor_size(0, &sl.m_width, &sl.m_height);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	sl.slx = mlx_init(sl.w_map * PPT, sl.h_map * PPT, "Test", true);
	if (sl.slx == NULL)
		sl_close("Error");
	
	sl.move_cnt = 0;	
	
	sl_load_texture(sl, texture, sl.hero, HERO);
	sl_load_texture(sl, texture, sl.item, ITEM);
	sl_load_texture(sl, texture, sl.bckg, BCKG);
	sl_load_texture(sl, texture, sl.wall, WALL);
	sl_load_texture(sl, texture, sl.exit, EXIT);
	
	sl_load_image(&sl);
	mlx_close_hook(sl.slx, sl_close, "Closing\n");	
	mlx_key_hook(sl.slx, &sl_keyhook, &sl);
	mlx_loop(sl.slx);
	sl_close("");
	return (0);
}
