/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:36:26 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 01:51:42 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	activate_anim(t_map *map, t_anim *out, t_anim *in)
{
	size_t	i;
	int32_t	x;
	int32_t	y;

	i = 0;
	while (i < out->count)
	{
		x = in->img[0]->instances[map->inst].x;
		y = in->img[0]->instances[map->inst].y;
		out->img[i]->instances[map->inst].x = x;
		out->img[i++]->instances[map->inst].y = y;
	}
	out->img[0]->instances[map->inst].enabled = true;
}

void	switch_img(t_map *map, t_anim *out, t_anim *in)
{
	size_t	i;
	int32_t	x;
	int32_t	y;

	i = 0;
	while (i < in->count)
		in->img[i++]->instances[map->inst].enabled = false;
	i = 0;
	while (i < out->count)
	{
		x = in->img[0]->instances[map->inst].x;
		y = in->img[0]->instances[map->inst].y;
		out->img[i]->instances[map->inst].x = x;
		out->img[i++]->instances[map->inst].y = y;
	}
	out->img[0]->instances[map->inst].enabled = true;
	map->cur_a = out;
}

void	switch_hero(t_anim *out, t_anim *in)
{
	size_t	i;
	int32_t	x;
	int32_t	y;

	i = 0;
	while (i < in->count)
		in->img[i++]->instances[0].enabled = false;
	i = 0;
	while (i < out->count)
	{
		x = in->img[0]->instances[0].x;
		y = in->img[0]->instances[0].y;
		out->img[i]->instances[0].x = x;
		out->img[i++]->instances[0].y = y;
	}
	out->img[0]->instances[0].enabled = true;
}

static void	switch_direction_loop(t_anim *out, t_anim *in)
{
	size_t	i;

	i = 0;
	while (i < out->count)
	{
		out->img[i]->instances[0].x = in->img[0]->instances[0].x;
		out->img[i]->instances[0].y = in->img[0]->instances[0].y;
		out->img[i++]->instances[0].enabled = true;
	}
	i = 0;
	while (i < in->count)
		in->img[i++]->instances[0].enabled = false;
}

void	switch_direction(t_win *sl, int32_t move[2])
{
	if (sl->dir == 'R' && move[X] < 0)
	{
		sl->dir = 'L';
		switch_direction_loop(sl->cat->hero_idle_m, sl->cat->hero_idle);
		sl->hero = sl->cat->hero_idle_m;
	}
	else if (sl->dir == 'L' && move[X] > 0)
	{
		sl->dir = 'R';
		switch_direction_loop(sl->cat->hero_idle, sl->cat->hero_idle_m);
		sl->hero = sl->cat->hero_idle;
	}
}
