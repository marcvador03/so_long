/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:06:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 21:17:05 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	kill_monster(t_win *sl, t_map **map_adj)
{
	int	i;

	i = 0;
	while (map_adj[i] != NULL)
	{
		if (map_adj[i]->c == 'M')
		{
			switch_img(map_adj[i], sl->cat->mons_dead, sl->cat->mons);
			map_adj[i]->c = '0';
		}
		i++;
	}
}

void	weapon_launch(t_win *sl, keys_t key)
{
	mlx_image_t	*img;

	if (key == MLX_KEY_RIGHT)
		img = sl->cat->arrow_r->img[0];
	if (key == MLX_KEY_LEFT)
		img = sl->cat->arrow_l->img[0];
	if (key == MLX_KEY_DOWN)
		img = sl->cat->arrow_down->img[0];
	if (key == MLX_KEY_UP)
		img = sl->cat->arrow_up->img[0];
	img->instances[0].x = sl->hero->img[0]->instances[0].x;
	img->instances[0].y = sl->hero->img[0]->instances[0].y;
	img->instances[0].enabled = true;
}

void	collect_item(t_win *sl, t_map **map, t_map a)
{
	switch_img(&map[a.y][a.x], sl->cat->item_o, sl->cat->item_c);
	activate_anim(&map[a.y][a.x], sl->cat->mush, sl->cat->item_o);
	map[a.y][a.x].c = '0';
	sl->item_cnt--;
}
