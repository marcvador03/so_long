/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:06:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/01 01:33:06 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	activate(t_anim *a, int n)
{
	//manage NULL value
	a->enabled = true;
	a->img[0]->instances[n].enabled = true;
}

void	de_activate(t_anim *a, int n)
{
	size_t	i;

	//manage NULL value
	a->enabled = false;
	i = 0;
	while (i < a->count)
		a->img[i++]->instances[n].enabled = false;
}

static void	move_hero(t_win *sl, keys_t key, t_map *map)
{
	int32_t	move[2];

	if (key == MLX_KEY_RIGHT)
		move[X] = MOVE;
	if (key == MLX_KEY_LEFT)
		move[X] = -MOVE;
	if (key == MLX_KEY_UP)
		move[Y] = -MOVE;
	if (key == MLX_KEY_DOWN)
		move[Y] = MOVE;
	map->cur_a->img[0]->instances[map->inst].x += move[X]; //manage image frames
	map->cur_a->img[0]->instances[map->inst].y += move[Y]; //manage image frames
	sl->h_hero += move[Y] / PPT;
	sl->w_hero += move[X] / PPT;
}

void	keyhook(mlx_key_data_t k, void *param)
{
	t_win	*sl;
	t_map	map;
	size_t	n;

	sl = (t_win *)param;
	map = sl->map[sl->h_hero][sl->w_hero];
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
		exp_close(&sl);
	if (k.key >= MLX_KEY_RIGHT && k.key <= MLX_KEY_UP && k.action >= MLX_PRESS)
	{
		n = move_init(sl, k.key, map);
		if (n == 1)
		{
			move_hero(sl, k.key, &map); 
			sl->move_cnt++;
			mlx_delete_image(sl->mlx, sl->s_cnt);
			sl->s_cnt = mlx_put_string(sl->mlx, ft_itoa(sl->move_cnt), 110, 0);
		}
		else if (n == 2)
			exit(1);
	}
}
