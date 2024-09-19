/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:39:03 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/19 15:25:30 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_load_image(t_mainwindow *sl)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;
	
	i = 0;
	n = 0;
	while (i <= sl->h_map - 1)
	{
		j = 0;
		while (j <= sl->w_map - 1)
		{
			if (sl->map[i][j].c == '0')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == '1')
			{
				mlx_image_to_window(sl->slx, sl->wall, j * PPT, i * PPT);
				n = sl->wall->count - 1;
				mlx_set_instance_depth(&sl->wall->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'E')
			{
				mlx_image_to_window(sl->slx, sl->exit, j * PPT, i * PPT);
				n = sl->exit->count - 1;
				mlx_set_instance_depth(&sl->exit->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'C')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
				mlx_image_to_window(sl->slx, sl->item, j * PPT, i * PPT);
				n = sl->item->count - 1;
				mlx_set_instance_depth(&sl->item->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'P')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
				mlx_image_to_window(sl->slx, sl->hero, j * PPT, i * PPT);
				n = sl->hero->count - 1;
				mlx_set_instance_depth(&sl->hero->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			j++;
		}
		i++;
	}
}
void	sl_load_texture(t_mainwindow sl, mlx_texture_t *txt, mlx_image_t *img, char *path)
{
	txt = mlx_load_png(path);
	if (txt == NULL)
		sl_close("Error loading texture");
	sl.hero = mlx_texture_to_image(sl.slx, txt);
	if(mlx_resize_image(img, PPT, PPT) == false)
		sl_close("Error resizing image");
}
