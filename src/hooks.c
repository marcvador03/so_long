/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:37:55 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 01:33:38 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	hook_mons_dead(void *ptr)
{
	t_win	*sl;
	size_t	i;
	size_t	j;
	size_t	x;

	sl = (t_win *)ptr;
	j = 0;
	while (j < sl->cat->mons_dead->count)
	{
		i = 0;
		x = sl->cat->mons_dead->img[j]->count;
		while (i < x)
		{
			if (sl->cat->mons_dead->img[j]->instances[i].enabled == true)
				anime_object(sl, sl->cat->mons_dead, i, 1);
			i++;
		}
		j++;
	}
}

void	hook_idle(void *ptr)
{
	t_win	*sl;

	sl = (t_win *)ptr;
	anime_object(sl, sl->hero, 0, 0);
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
				anime_object(sl, sl->cat->mons, i, 0);
			i++;
		}
		j++;
	}
}
