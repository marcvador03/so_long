/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:41:47 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 21:19:10 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook_key(mlx_key_data_t k, void *param)
{
	t_win		*sl;

	sl = (t_win *)param;
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
		esc_close(sl, sl->map);
	if (k.modifier == MLX_SHIFT && k.action == MLX_PRESS)
	{
		if (k.key >= MLX_KEY_RIGHT && k.key <= MLX_KEY_UP)
			weapon_launch(sl, k.key);
	}
	else if (k.key >= MLX_KEY_RIGHT && k.key <= MLX_KEY_UP)
	{
		if (k.action >= MLX_PRESS)
			move_init(sl, k.key);
	}
}

void	hook_close(void *ptr)
{
	t_win	*sl;

	sl = (t_win *)ptr;
	if (sl->map != NULL)
		free_map(sl);
	if (sl->cat != NULL)
		free_cat(sl->mlx, sl->cat);
	if (sl->str_move != NULL)
		mlx_delete_image(sl->mlx, sl->str_move);
	mlx_delete_image(sl->mlx, sl->str_move);
}
