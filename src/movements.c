/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:17:46 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 10:55:51 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_mush(t_win *sl, mlx_image_t *img, int32_t n)
{
	int32_t	*frame;
	int32_t	sign;

	frame = &sl->cat->mush->frame[0][n];
	sign = ((*frame - (PPT / 2)) > 0) - ((*frame - (PPT / 2)) < 0);
	sl->cat->mush->time += sl->mlx->delta_time * 1000;
	if (sl->cat->mush->time > sl->cat->mush->fps)
	{
		sl->cat->mush->time -= sl->cat->mush->fps;
		if (*frame < PPT)
			img->instances[n].y += 1 * sign;
		else if (*frame >= PPT)
			img->instances[n].enabled = false;
		*frame += 1;
	}
}

static void	move_hero(t_win *sl, keys_t key)
{
	int32_t	move[2];
	size_t	i;

	move[X] = 0;
	move[Y] = 0;
	i = 0;
	if (key == MLX_KEY_RIGHT)
		move[X] = MOVE;
	if (key == MLX_KEY_LEFT)
		move[X] = -MOVE;
	if (key == MLX_KEY_UP)
		move[Y] = -MOVE;
	if (key == MLX_KEY_DOWN)
		move[Y] = MOVE;
	while (i < sl->hero->count)
	{
		sl->hero->img[i]->instances[0].x += move[X];
		sl->hero->img[i++]->instances[0].y += move[Y];
	}
	switch_direction(sl, move);
}

void	move_weapon_init(t_win *sl, t_anim *a)
{
	size_t		n;
	int32_t		*move;
	int32_t		*hero;

	a->time += sl->mlx->delta_time * 1000;
	move = fill_move(sl, a, 0);
	hero = fill_coord(sl, a, 0);
	if (a->time > a->fps)
	{
		a->time -= a->fps;
		n = move_auth_init(sl, 0, a);
		if (n == 0)
			a->img[0]->instances[0].enabled = false;
		else if (n == 3)
			kill_monster(sl, identify_adj_map(sl, move, hero), a);
		else
		{
			a->img[0]->instances[0].x += move[X] * 4;
			a->img[0]->instances[0].y += move[Y] * 4;
		}
		free(move);
		free(hero);
	}
}

void	move_init(t_win *sl, keys_t key)
{
	size_t	n;
	char	*str;

	n = move_auth_init(sl, key, sl->hero);
	if (n == 1)
	{
		move_hero(sl, key);
		sl->move_cnt++;
		if (sl->s_cnt != NULL)
			mlx_delete_image(sl->mlx, sl->s_cnt);
		str = ft_itoa(sl->move_cnt);
		if (str == NULL)
			unexpected_close(ERR_MALLOC, sl);
		sl->s_cnt = mlx_put_string(sl->mlx, str, 110, 0);
		free(str);
	}
	else if (n == 2)
		esc_close(sl, sl->map);
	else if (n == 3)
		esc_close(sl, sl->map);
}
