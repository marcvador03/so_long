/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:06:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 23:09:41 by mfleury          ###   ########.fr       */
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



/*size_t	move_hero(t_anim *idle, t_anim *run, int32_t move[2])
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
}*/

/*static void	sl_move_action(t_win *sl, mlx_image_t **img)
{
	uint32_t	i;
	uint32_t	j;
	size_t		n;

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
}*/

void	keyhook(mlx_key_data_t k, void *param)
{
	t_win	*sl;
	t_map	map;

	sl = (t_win *)param;
	map = sl->map[sl->h_hero][sl->w_hero];
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
		exp_close(sl);
	if (k.key >= MLX_KEY_RIGHT && k.key <= MLX_KEY_UP && k.action >= MLX_PRESS)
	{
		if (move_init(sl, k.key, map) > 0)
		{
			sl->move_cnt++;
			ft_printf("Current #movements: %d\n", sl->move_cnt);
			//sl_move_action(sl, sl->cat->h_idle->img);
		}
	}
}
