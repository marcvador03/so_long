/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:06:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/02 20:32:50 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	activate_anim(t_map *map, t_anim *out, t_anim *in) // remove map.inst?
{
	size_t	i;
	
	i = 0;
	while (i < out->count)
	{
		out->img[i]->instances[map->inst].x = in->img[0]->instances[map->inst].x;
		out->img[i++]->instances[map->inst].y = in->img[0]->instances[map->inst].y;
	}
	out->img[0]->instances[map->inst].enabled = true;
}

void	switch_img(t_map *map, t_anim *out, t_anim *in) // removed map inst
{
	size_t	i;
	
	i = 0;
	while (i < in->count)
		in->img[i++]->instances[map->inst].enabled = false;
	i = 0;
	while (i < out->count)
	{
		out->img[i]->instances[map->inst].x = in->img[0]->instances[map->inst].x;
		out->img[i++]->instances[map->inst].y = in->img[0]->instances[map->inst].y;
	}
	out->img[0]->instances[map->inst].enabled = true;
	map->cur_a = out;
}

static void switch_direction_loop(t_anim *out, t_anim *in)
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

static void switch_direction(t_win *sl, int32_t move[2])
{

	if (sl->dir =='R' && move[X] < 0)
	{
		sl->dir = 'L';
		switch_direction_loop(sl->cat->hero_idle_m, sl->cat->hero_idle);	
		sl->hero = sl->cat->hero_idle_m;
	}
	else if (sl->dir =='L' && move[X] > 0)
	{
		sl->dir = 'R';
		switch_direction_loop(sl->cat->hero_idle, sl->cat->hero_idle_m);	
		sl->hero = sl->cat->hero_idle;
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

static void	move_init(t_win *sl, keys_t key)
{
	size_t	n;
	
	n = move_auth_init(sl, key, sl->hero);
	if (n == 1)
	{
		move_hero(sl, key); 
		sl->move_cnt++;
		if (sl->s_cnt != NULL)
			mlx_delete_image(sl->mlx, sl->s_cnt);
		sl->s_cnt = mlx_put_string(sl->mlx, ft_itoa(sl->move_cnt), 110, 0);
	}
	else if (n == 2)
		exit(1);
	else if (n == 3)
		exit(0);
}

static void	weapon_launch(t_win *sl, keys_t key)
{
	mlx_image_t *img;

	if (key == MLX_KEY_RIGHT)
		img = sl->cat->arrow_r->img[0];
	if (key == MLX_KEY_LEFT)
		img = sl->cat->arrow_l->img[0];
	if (key == MLX_KEY_DOWN)
		img = sl->cat->arrow_down->img[0];
	if (key == MLX_KEY_UP)
		img = sl->cat->arrow_up->img[0];
	img->instances[0].x = sl->hero->img[0]->instances[0].x; 
	img->instances[0].y = sl->hero->img[0]->instances[0].y;
	img->instances[0].enabled = true;
}

void	keyhook(mlx_key_data_t k, void *param)
{
	t_win		*sl;
	//t_map		map;
	//uint32_t 	h_hero;
	//uint32_t	w_hero;

	sl = (t_win *)param;
	/*h_hero = sl->hero->img[0]->instances[0].y / PPT;
	w_hero = sl->hero->img[0]->instances[0].x / PPT;
	map = sl->map[h_hero][w_hero];*/
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
		esc_close(sl, sl->map);
	if (k.modifier == MLX_SHIFT && k.action == MLX_PRESS)
	{
		if (k.key >= MLX_KEY_RIGHT && k.key <= MLX_KEY_UP)
			weapon_launch(sl, k.key);
	}
	else if (k.key >= MLX_KEY_RIGHT && k.key <= MLX_KEY_UP && k.action >= MLX_PRESS)
		move_init(sl, k.key);
}
