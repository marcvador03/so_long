/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:06:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/27 12:02:56 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		{
			n = move_init(sl, sl->cat, keydata.key, sl->cat->h_idle->img);
			if (n > 0)
			{
				sl->move_cnt += n;
				ft_printf("Current #movements: %d\n", sl->move_cnt);
				if (keydata.action == MLX_PRESS)
				/*{
					activate(sl->cat->h_idle, 0);
					de_activate(sl->cat->h_run, 0);
				}*/
				sl_move_action(sl, sl->cat->h_idle->img);
			}
		}
}
