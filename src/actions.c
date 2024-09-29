/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:06:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/29 18:51:22 by mfleury          ###   ########.fr       */
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

int	check_collision(t_map *map_adj, int32_t hero[4], int32_t move[2])
{
	int32_t	pos_adj[4];

	if (map_adj->c != '1')
		return (0);
	pos_adj[X] = map_adj->img[0]->instances[map_adj->instance].x;
	pos_adj[Y] = map_adj->img[0]->instances[map_adj->instance].y;
	pos_adj[X_W] = pos_adj[X] + map_adj->img[0]->width;
	pos_adj[Y_H] = pos_adj[Y] + map_adj->img[0]->height;
	if (move[X] > 0 && hero[X_W] + move[X] > pos_adj[X])
		return (1);
	if (move[X] < 0 && hero[X] + move[X] < pos_adj[X_W])
		return (1);
	if (move[Y] > 0 && hero[Y_H] + move[Y] > pos_adj[Y])
		return (1);
	if (move[Y] < 0 && hero[Y] + move[Y] < pos_adj[Y_H])
		return (1);
	return (0);
}

size_t	move_hero(t_anim *idle, t_anim *run, int32_t move[2])
{
	size_t	i;

	i = 0;
	//de_activate(idle, 0);
	//activate(run, 0);
	while (i < idle->count)
	{
		idle->img[i]->instances[0].x += move[X];
		idle->img[i++]->instances[0].y += move[Y];
	}
	i = 0;
	while (i < run->count)
	{
		run->img[i]->instances[0].x += move[X];
		run->img[i++]->instances[0].y += move[Y];
	}
	return (1);
}

static void	sl_move_action(t_win *sl, mlx_image_t **img)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	if (PPT < 0)
		unexpected_close(ERR_PPT, sl, sl->map);
	i = img[0]->instances[0].y / PPT;
	j = img[0]->instances[0].x / PPT;
	if (sl->map[i][j].c == 'C')
	{
		n = sl->map[i][j].instance;
		sl->cat->item->instances[n].enabled = false;
		sl->map[i][j].c = '0';
		sl->item_cnt--;
	}
	if (sl->map[i][j].c == 'E' && sl->item_cnt == 0)
		exp_close(&sl);//how to call success?
}

void	sl_keyhook(mlx_key_data_t keydata, void *param)
{
	t_win	*sl;
	size_t	n;

	sl = (t_win *)param;
	/*if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exp_close(sl);*/
	if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		{
			n = move_init(sl, sl->cat, keydata.key, sl->cat->h_idle->img);
			if (n > 0)
			{
				sl->move_cnt += n;
				ft_printf("Current #movements: %d\n", sl->move_cnt);
				/*if (keydata.action == MLX_PRESS)
				{
					activate(sl->cat->h_idle, 0);
					de_activate(sl->cat->h_run, 0);
				}*/
				sl_move_action(sl, sl->cat->h_idle->img);
			}
		}
	}
}
