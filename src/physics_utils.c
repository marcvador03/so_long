/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:51:33 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 21:44:43 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int32_t	*fill_move(t_win *sl, t_anim *a, keys_t key) // utils?
{
	int32_t	*move;

	move = (int32_t *)ft_calloc(sizeof(int32_t), 2);
	if (move == NULL)
		unexpected_close(ERR_MALLOC, sl);
	if ((key == MLX_KEY_RIGHT) || (key == 0 && a->name[6] == 'r'))
		move[X] = MOVE;
	if ((key == MLX_KEY_LEFT) || (key == 0 && a->name[6] == 'l'))
		move[X] = -MOVE;
	if ((key == MLX_KEY_UP) || (key == 0 && a->name[6] == 'u'))
		move[Y] = -MOVE;
	if ((key == MLX_KEY_DOWN) || (key == 0 && a->name[6] == 'd'))
		move[Y] = MOVE;
	return (move);
}

int32_t	*fill_coord(t_win *sl, t_anim *a, keys_t key) // utils?
{
	int32_t	*hero;

	hero = (int32_t *)ft_calloc(sizeof(int32_t), 5);
	if (hero == NULL)
		unexpected_close(ERR_MALLOC, sl);
	hero[4] = 0;
	if (key == 0)
		hero[4] = 1;
	hero[X] = a->img[0]->instances[0].x;
	hero[Y] = a->img[0]->instances[0].y;
	hero[X_W] = hero[X] + a->img[0]->width;
	hero[Y_H] = hero[Y] + a->img[0]->height;
	return (hero);
}

void	s_err(t_win *sl, size_t *cnt, t_sprite *s, mlx_texture_t *t)
{
	free(cnt);
	free(s);
	mlx_delete_texture(t);
	unexpected_close(ERR_SPRITE, sl);
}
