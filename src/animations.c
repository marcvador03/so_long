/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 21:14:58 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_anim	*create_anime(t_win *sl, double fps, int32_t z, char *name)
{
	t_anim	*anime;

	anime = (t_anim *)ft_calloc(sizeof(t_anim), 1);
	if (anime == NULL)
		unexpected_close(ERR_MALLOC, sl);
	anime->fps = fps;
	anime->depth = z;
	anime->name = name;
	return (anime);
}

static void	anime_obj_loop(int32_t frame, int32_t cnt[3], t_anim *a, int32_t i)
{
	if (frame == 0 && cnt[3] > 1)
	{
		a->img[cnt[2] - 1]->instances[i].x = cnt[X];
		a->img[cnt[2] - 1]->instances[i].y = cnt[Y];
		a->img[cnt[2] - 1]->instances[i].enabled = false;
	}
	else if (cnt[2] > 1)
	{
		a->img[frame - 1]->instances[i].x = cnt[X];
		a->img[frame - 1]->instances[i].y = cnt[Y];
		a->img[frame - 1]->instances[i].enabled = false;
	}
}

void	anime_object(t_win *sl, t_anim *a, int32_t i)
{
	int32_t	*frame;
	int32_t	cnt[3];

	frame = &a->frame[0][i];
	cnt[X] = a->img[*frame]->instances[i].x;
	cnt[Y] = a->img[*frame]->instances[i].y;
	a->time += sl->mlx->delta_time * 1000;
	if (a->time > a->fps)
	{
		a->img[*frame]->instances[i].enabled = true;
		cnt[2] = a->count;
		anime_obj_loop(*frame, cnt, a, i);
		a->time -= a->fps;
		*frame = (*frame + 1) % a->count;
	}
}

void	update_anim_frame(t_win *sl, t_anim *a)
{
	size_t	i;

	a->frame = (int32_t **)ft_calloc(sizeof(int32_t *), a->count);
	if (a->frame == NULL)
		unexpected_close(ERR_ANIME, sl);
	i = 0;
	while (i < a->count)
	{
		a->frame[i] = (int32_t *)ft_calloc(sizeof(int32_t), a->img[i]->count);
		if (a->frame[i++] == NULL)
			unexpected_close(ERR_ANIME, sl);
	}
}
