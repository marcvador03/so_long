/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/02 21:48:35 by mfleury          ###   ########.fr       */
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
	//anime->enabled = false;
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

void	hook_weapon(void *ptr)
{
	t_win	*sl;

	sl = (t_win *)ptr;
	if (sl->cat->arrow_up->img[0]->instances[0].enabled == true)
		move_weapon_init(sl, sl->cat->arrow_up);
	if (sl->cat->arrow_down->img[0]->instances[0].enabled == true)
		move_weapon_init(sl, sl->cat->arrow_down);
	if (sl->cat->arrow_r->img[0]->instances[0].enabled == true)
		move_weapon_init(sl, sl->cat->arrow_r);
	if (sl->cat->arrow_l->img[0]->instances[0].enabled == true)
		move_weapon_init(sl, sl->cat->arrow_l);
}

void	dead_mons(t_win *sl, int32_t i)
{
	int32_t	*frame;
	int32_t	x;
	int32_t	y;

	frame = &sl->cat->mons_dead->frame[0][i];
	x = sl->cat->mons_dead->img[*frame]->instances[i].x;
	y = sl->cat->mons_dead->img[*frame]->instances[i].y;
	sl->cat->mons_dead->time += sl->mlx->delta_time * 1000;
	if (sl->cat->mons_dead->time > sl->cat->mons_dead->fps)
	{
		sl->cat->mons_dead->img[*frame]->instances[i].enabled = true;
		if (*frame == 0 && sl->cat->mons_dead->count > 1)
		{
			sl->cat->mons_dead->img[sl->cat->mons_dead->count - 1]->instances[i].x = x;
			sl->cat->mons_dead->img[sl->cat->mons_dead->count - 1]->instances[i].y = y;
			sl->cat->mons_dead->img[sl->cat->mons_dead->count - 1]->instances[i].enabled = false;
		}
		else if (sl->cat->mons_dead->count > 1)
		{
			sl->cat->mons_dead->img[*frame - 1]->instances[i].x = x;
			sl->cat->mons_dead->img[*frame - 1]->instances[i].y = y;
			sl->cat->mons_dead->img[*frame - 1]->instances[i].enabled = false;
		}
		sl->cat->mons_dead->time -= sl->cat->mons_dead->fps;
		*frame = (*frame + 1) % sl->cat->mons_dead->count;
	}
}

void	idle_mons(t_win *sl, int32_t i)
{
	int32_t	*frame;
	int32_t	x;
	int32_t	y;

	frame = &sl->cat->mons->frame[0][i];
	x = sl->cat->mons->img[*frame]->instances[i].x;
	y = sl->cat->mons->img[*frame]->instances[i].y;
	sl->cat->mons->time += sl->mlx->delta_time * 1000;
	if (sl->cat->mons->time > sl->cat->mons->fps)
	{
		sl->cat->mons->img[*frame]->instances[i].enabled = true;
		if (*frame == 0 && sl->cat->mons->count > 1)
		{
			sl->cat->mons->img[sl->cat->mons->count - 1]->instances[i].x = x;
			sl->cat->mons->img[sl->cat->mons->count - 1]->instances[i].y = y;
			sl->cat->mons->img[sl->cat->mons->count - 1]->instances[i].enabled = false;
		}
		else if (sl->cat->mons->count > 1)
		{
			sl->cat->mons->img[*frame - 1]->instances[i].x = x;
			sl->cat->mons->img[*frame - 1]->instances[i].y = y;
			sl->cat->mons->img[*frame - 1]->instances[i].enabled = false;
		}
		sl->cat->mons->time -= sl->cat->mons->fps;
		*frame = (*frame + 1) % sl->cat->mons->count;
	}
}

void	hook_mons_dead(void *ptr)
{
	t_win	*sl;
	size_t	i;
	size_t	j;
	
	sl = (t_win *)ptr;
	j = 0;
	while (j < sl->cat->mons_dead->count)
	{
		i = 0;
		while (i < sl->cat->mons_dead->img[j]->count)
		{
			if (sl->cat->mons_dead->img[j]->instances[i].enabled == true)
				dead_mons(sl, i);
			i++;
		}
		j++;
	}
}

void	hook_mons(void *ptr)
{
	t_win	*sl;
	size_t	i;
	size_t	j;


	sl = (t_win *)ptr;
	j = 0;
	while (j < sl->cat->mons->count)
	{
		i = 0;
		while (i < sl->cat->mons->img[j]->count)
		{
			if (sl->cat->mons->img[j]->instances[i].enabled == true)
				idle_mons(sl, i);
			i++;
		}
		j++;
	}

}
		
void	hook_idle(void *ptr)
{
	t_win	*sl;

	sl = (t_win *)ptr;
			anime_hero(sl);
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

void	kill_monster(t_win *sl, t_map **map_adj)
{
	int	i;

	i = 0;
	while (map_adj[i] != NULL)
	{  	
		if (map_adj[i]->c == 'M')
		{
			switch_img(map_adj[i], sl->cat->mons_dead, sl->cat->mons);	
			map_adj[i]->c = '0';
		}
		i++;
	}
}

void	move_weapon_init(t_win *sl, t_anim *a) 
{
	size_t		n;
	int32_t		*move;

	move = NULL;
	a->time += sl->mlx->delta_time * 1000;
	move = fill_move(a, 0);
	if (a->time > a->fps)
	{
		a->time -= a->fps;
		n = move_auth_init(sl, 0, a);
		if (n == 0)
		{
			a->img[0]->instances[0].enabled = false;
		}
		else if (n == 3)
		{
			a->img[0]->instances[0].enabled = false;
			kill_monster(sl, identify_adj_map(sl, move, fill_coord(a, 0)));
		}
		else
		{
			a->img[0]->instances[0].x += move[X] * 4;
			a->img[0]->instances[0].y += move[Y] * 4;
		}
		free(move);
	}
}

void	anime_hero(t_win *sl) 
{
	int32_t	*frame;
	int32_t	x;
	int32_t	y;

	frame = &sl->hero->frame[0][0];
	x = sl->hero->img[*frame]->instances[0].x;
	y = sl->hero->img[*frame]->instances[0].y;
	sl->hero->time += sl->mlx->delta_time * 1000;
	if (sl->hero->time > sl->hero->fps)
	{
		sl->hero->img[*frame]->instances[0].enabled = true;
		if (*frame == 0 && sl->hero->count > 1)
		{
			sl->hero->img[sl->hero->count - 1]->instances[0].x = x;
			sl->hero->img[sl->hero->count - 1]->instances[0].y = y;
			sl->hero->img[sl->hero->count - 1]->instances[0].enabled = false;
		}
		else if (sl->hero->count > 1)
		{
			sl->hero->img[*frame - 1]->instances[0].x = x;
			sl->hero->img[*frame - 1]->instances[0].y = y;
			sl->hero->img[*frame - 1]->instances[0].enabled = false;
		}
		sl->hero->time -= sl->hero->fps;
		*frame = (*frame + 1) % sl->hero->count;
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
