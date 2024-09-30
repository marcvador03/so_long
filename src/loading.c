/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:39:03 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 21:39:07 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	img_to_win(mlx_t *mlx, mlx_image_t *img, uint32_t p[2], int32_t z)
{
	size_t	n;

	if (img == NULL)
		return (0);
	n = 0;
	mlx_image_to_window(mlx, img, p[W] * PPT, p[H] * PPT);
	n = img->count - 1;
	mlx_set_instance_depth(&img->instances[n], z);
	img->instances[n].enabled = true;
	return (n);
}

void	attach_static_image(t_win *sl, t_map map, t_cat *cat, uint32_t cnt[2])
{
	mlx_image_t	**img;
	int32_t		z;

	img = NULL;
	z = 1;
	if (map.c == '1')
		map.img = &cat->wall;
	else if (map.c == 'C')
		map.img = &cat->item;
	else if (map.c == 'P')
	{
		map.img = &cat->hero;
		z = 2;
		sl->hero->w_hero = cnt[W];
		sl->hero->h_hero = cnt[H];
	}
	map.instance = img_to_win(sl->mlx, *map.img, cnt, z);
	map.img = &cat->bckg;
	map.instance = img_to_win(sl->mlx, *map.img, cnt, 0);
}

void	load_static_image(t_win *sl, t_cat *cat)
{
	uint32_t	cnt[2];
	t_map		map;

	cnt[H] = 0;
	while (cnt[H] < sl->h_map)
	{
		cnt[W] = 0;
		while (cnt[W] < sl->w_map)
		{
			map = sl->map[cnt[H]][cnt[W]];
			attach_static_image(sl, map, cat, cnt);
			cnt[W]++;
		}
		cnt[H]++;
	}
}

void	attach_image(t_win *sl, t_map map, t_anim *a, uint32_t cnt[2])
{
	int32_t	i;
	
	i = 0;
	while (i < a->count)
	{
		*mlx_image_to_window(mlx, a->img[i], p[W] * PPT, p[H] * PPT);
		n = a->img[i]->count - 1;
		mlx_set_instance_depth(&a->img[i]->instances[n], a->depth);
		a->img[i]->instances[n].enabled = false;
	}
	map.anim = &a;
	map.cur_img = 0;
	map.inst = map.anim->img[0]->count - 1;,
	a->img[0]->instances[n].enabled = true;
}

void	load_sprite(mlx_t *mlx, t_sprite *s, t_anim *a, uint32_t p[2])
{
	int32_t	i;

	if (s == NULL || s->count <= 0 || a == NULL)
		return (0);
	a->img = (mlx_image_t **)ft_calloc(s->count, sizeof(mlx_image_t *));
	if (a->img == NULL)
		return (0);
	i = 0;
	while (i < s->count)
	{
		a->img[i] = mlx_texture_to_image(mlx, s->texture[i]);
		if (mlx_resize_image(a->img[i], s->r_width, s->r_height) == false)
			return (0);
		/*mlx_image_to_window(mlx, a->img[i], p[W] * PPT, p[H] * PPT);
		n = a->img[i]->count - 1;
		a->img[i]->instances[n].enabled = false;
		mlx_set_instance_depth(&a->img[i]->instances[n], a->depth);*/
		i++;
	}
	a->count = s->count;
	return (1)
}

void	load_dynamic_image(t_win *sl, t_anim *a, t_sprite *sprite, char c)
{
	uint32_t	cnt[2];
	t_map		map;
	size_t		n;

	n = 0;
	cnt[H] = 0;
	load_sprite(sl.mlx, sprite, a, cnt);
	//delete sprite + malloc
	while (cnt[H] < sl->h_map)
	{
		cnt[W] = 0;
		while (cnt[W] < sl->w_map)
		{
			if (sl->map[cnt[H]][cnt[W]].c = c)
			{
				map = sl->map[cnt[H]][cnt[W]];
				attach_image(sl, map, cat, cnt);
			}
			cnt[W]++;
		}
		cnt[H]++;
	}
}
