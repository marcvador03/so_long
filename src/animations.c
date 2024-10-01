/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/02 00:09:17 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_anim	*create_anime(double fps, int32_t z, char *name)
{
	t_anim	*anime;

	anime = (t_anim *)ft_calloc(sizeof(t_anim), 1);
	if (anime == NULL)
		return (NULL);
	anime->fps = fps;
	anime->depth = z;
	anime->name = name;
	anime->enabled = false;
	return (anime);
}

void	hook_mush(void *ptr)
{
	t_win	*sl;
	size_t	i;

	sl = (t_win *)ptr;
	i = 0;
	while (i < sl->cat->mush->img[0]->count)
	{
		if (sl->cat->mush->img[0]->instances[i].enabled == true)
			move_mush(sl, sl->cat->mush->img[0], i);
		i++;	
	}
}

void	hook_idle(void *ptr)
{
	t_win	*sl;
	size_t	i;

	sl = (t_win *)ptr;
	i = 0;
	while (i < sl->hero->count)
	{
		if (sl->hero->img[i]->enabled == true)
			anime_hero(sl, i);
		i++;	
	}
}

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
			img->instances[n].y	+= 1 * sign;
		else if (*frame >= PPT)
			img->instances[n].enabled = false;
		*frame += 1;
	}
}

void	anime_hero(t_win *sl, int32_t n) 
{
	int32_t	*frame;
	int32_t	next_frame;

	frame = &sl->hero->frame[0][0];
	sl->hero->time += sl->mlx->delta_time * 1000;
	if (sl->hero->time > sl->hero->fps)
	{
		sl->hero->time -= sl->hero->fps;
		next_frame = (*frame + 1) % sl->hero->count;
		sl->hero->img[next_frame]->enabled = true;
		sl->hero->img[*frame]->enabled = false;
		*frame = next_frame;
	}
}







/*void	anime_sprite(void *ptr)
{
	double	time[2];
	t_anim	*anime;
	int		i;

	anime = (t_anim *)ptr;
	if (anime->enabled == false)
		return ;
	i = anime->frame;
	time[0] = mlx_get_time();
	time[1] = time[0];
	while ((time[1] - anime->fps) <= time[0])
		time[1] = mlx_get_time();
	anime->img[i]->instances[0].enabled = true;
	if (i == 0 && anime->count > 1)
		anime->img[anime->count - 1]->instances[0].enabled = false;
	else if (anime->count > 1)
		anime->img[i - 1]->instances[0].enabled = false;
	anime->img[i]->instances[0].x += anime->x_move;
	anime->img[i]->instances[0].y += anime->y_move;
	anime->frame = (anime->frame + 1) % anime->count;
}*/
