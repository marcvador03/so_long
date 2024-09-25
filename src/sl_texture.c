/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:39:03 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/25 10:30:49 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static size_t	load_sprite(mlx_t *slx, t_sprite *s, t_anim *a, uint32_t p[3])
{
	size_t			i;
	size_t			n;
	mlx_image_t		**img;
	
	if (s == NULL || s->count <= 0)
		return (0);
	img = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * s->count);
	if (img == NULL)
		return (0);
	i = 0;
	n = 0;
	while (i < s->count)
	{
		img[i] = mlx_texture_to_image(slx, s->texture[i]);
		if(mlx_resize_image(img[i], s->r_width, s->r_height) == false)
			return (0);
		mlx_image_to_window(slx, img[i], p[W], p[H]);
		n = img[i]->count - 1;
		img[i]->instances[0].enabled = false;
		mlx_set_instance_depth(&img[i]->instances[n], (int32_t)p[2]);
		i++;
	}
	img[s->count - 1]->instances[0].enabled = true;
	if (a == NULL)
		return (n);		
	a->img = img;
	a->count = s->count;
	return (n);
}

static size_t	load(mlx_t *slx, mlx_image_t *img, uint32_t p[2], int32_t z)
{
	size_t	n;

	if (img == NULL)
		return (0);
	n = 0;
	mlx_image_to_window(slx, img, p[W] * PPT, p[H] * PPT);
	n = img->count - 1;
	mlx_set_instance_depth(&img->instances[n], z);
	return (n);
}

static size_t	update_map(t_map *map, mlx_image_t **img, size_t n)
{
	map->instance = n;
	map->img = img;

	return (map->instance);
}

void	load_static_image(t_mainwindow *sl)
{
	uint32_t	cnt[2];
	size_t	n;
	
	n = 0;
	cnt[H] = 0;
	while (cnt[H] <= sl->h_map - 1)
	{
		cnt[W] = 0;
		while (cnt[W] <= sl->w_map - 1)
		{
			//n = load(sl.slx, sl.bckg, cnt, 0);
			//update_map(sl.map[cnt[H]][cnt[W]], &sl.bckg, n);
			//sl.map[cnt[H]][cnt[W]].instance = n;*/
			if (sl->map[cnt[H]][cnt[W]].c == '1')
			{
				n = load(sl->slx, sl->wall, cnt, 1);
				update_map(&sl->map[cnt[H]][cnt[W]], &sl->wall, n);
			}
			else if (sl->map[cnt[H]][cnt[W]].c == 'C')
			{	
				n = load(sl->slx, sl->item, cnt, 2);
				update_map(&sl->map[cnt[H]][cnt[W]], &sl->item, n);
			}
			else if (sl->map[cnt[H]][cnt[W]].c == 'P')
			{	
				n = load(sl->slx, sl->hero, cnt, 3);
				update_map(&sl->map[cnt[H]][cnt[W]], &sl->hero, n);
			}
			cnt[W]++;
		}
		cnt[H]++;
	}
}

void	load_dynamic_image(t_mainwindow sl, t_sprite *sprite)
{
	uint32_t	cnt[3];
	size_t	n;
	
	n = 0;
	cnt[H] = 0;
	while (cnt[H] <= sl.h_map - 1)
	{
		cnt[W] = 0;
		while (cnt[W] <= sl.w_map - 1)
		{
			if (sl.map[cnt[H]][cnt[W]].c == 'P')
			{
				cnt[2] = 3;
				n = load_sprite(sl.slx, sprite, sl.hero_idle, cnt);
				if (n == 0)
					unexpected_close(ERR_SPRITE, &sl, sl.map);
				sl.map[cnt[H]][cnt[W]].instance = n;
			}
			cnt[W]++;
		}
		cnt[H]++;
	}
}


















/*void	sl_load_image(t_mainwindow sl)
{
	int32_t	i;
	int32_t	j;
	size_t	n;
	
	i = 0;
	n = 0;
	while (i <= sl.h_map - 1)
	{
		j = 0;
		while (j <= sl.w_map - 1)
		{
			if (sl->map[i][j].c == '0')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
			}
			if (sl.map[i][j].c == '1')
			{
				mlx_image_to_window(sl.slx, sl.wall, j * PPT, i * PPT);
				n = sl.wall->count - 1;
				mlx_set_instance_depth(&sl.wall->instances[n], 3);
				sl.map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'E')
			{
				mlx_image_to_window(sl->slx, sl->exit, j * PPT, i * PPT);
				n = sl->exit->count - 1;
				mlx_set_instance_depth(&sl->exit->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'C')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
				mlx_image_to_window(sl->slx, sl->item, j * PPT, i * PPT);
				n = sl->item->count - 1;
				mlx_set_instance_depth(&sl->item->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'P')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
				mlx_image_to_window(sl->slx, sl->hero, j * PPT, i * PPT);
				n = sl->hero->count - 1;
				mlx_set_instance_depth(&sl->hero->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			j++;
		}
		i++;
	}
}*/
