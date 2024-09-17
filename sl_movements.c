/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:37:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/14 12:37:31 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	sl_move_authorized(t_mainwindow *sl, keys_t key)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	n = 0;
	if (PPT < 0)
		sl_close("Error in pixel per tile PPT definition");
	i = sl->hero->instances[0].y / PPT;
	j = sl->hero->instances[0].x / PPT;
	if (key == MLX_KEY_RIGHT && j < sl->w_map)
		if (sl->map[i][j + 1].c != '1')
			sl->hero->instances[n++].x += PPT;
	if (key == MLX_KEY_LEFT && j > 0)
		if (sl->map[i][j - 1].c != '1')
			sl->hero->instances[n++].x -= PPT;
	if (key == MLX_KEY_UP && i > 0)
		if (sl->map[i - 1][j].c != '1')
			sl->hero->instances[n++].y -= PPT;
	if (key == MLX_KEY_DOWN && i < sl->h_map)
		if (sl->map[i + 1][j].c != '1')
			sl->hero->instances[n++].y += PPT;
	return (n);	
}

void	sl_move_action(t_mainwindow *sl)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	if (PPT < 0)
		sl_close("Error in pixel per tile PPT definition");
	i = sl->hero->instances[0].y / PPT;
	j = sl->hero->instances[0].x / PPT;
	if (sl->map[i][j].c == 'C')
	{
		n = sl->map[i][j].instance;
		sl->item->instances[n].enabled = false;
		sl->map[i][j].c = '0';
		sl->item_cnt--;
	}
	if (sl->map[i][j].c == 'E' && sl->item_cnt == 0)
		sl_close("Success!!!\n");
}

void	sl_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mainwindow *sl;
	size_t		n;

	sl = (t_mainwindow *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		sl_close("Closing with ESC\n");
	if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		{
			n = sl_move_authorized(sl, keydata.key);
			if (n > 0)
			{
				sl->move_cnt += n;
				ft_printf("Current #movements: %d\n", sl->move_cnt);
				sl_move_action(sl);
			}
		}
}
