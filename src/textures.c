/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:39:03 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/26 15:43:48 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	activate(t_anim *a, int n)
{
		a->enabled = true;
		a->img[0]->instances[n].enabled = true;	
}

void	de_activate(t_anim *a, int n)
{
	size_t	i;

	a->enabled = false;
	i = 0;
	while (i < a->count)
		a->img[i++]->instances[n].enabled = false;	
		
}

static size_t	load_sprite(mlx_t *mlx, t_sprite *s, t_anim *a, uint32_t p[3])
{
	size_t			i;
	size_t			n;
	
	if (s == NULL || s->count <= 0 || a == NULL)
		return (0);
	a->img = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * s->count);
	if (a->img == NULL)
		return (0);
	i = 0;
	n = 0;
	a->enabled = false;
	while (i < s->count)
	{
		a->img[i] = mlx_texture_to_image(mlx, s->texture[i]);
		if(mlx_resize_image(a->img[i], s->r_width, s->r_height) == false)
			return (0);
		mlx_image_to_window(mlx, a->img[i], p[W] * PPT, p[H] * PPT);
		n = a->img[i]->count - 1;
		a->img[i]->instances[0].enabled = false;
		mlx_set_instance_depth(&a->img[i]->instances[n], (int32_t)p[2]);
		i++;
	}
//	a->img[s->count - 1]->instances[0].enabled = true;
	a->count = s->count;
	return (1);
}

static size_t	load(mlx_t *mlx, mlx_image_t *img, uint32_t p[2], int32_t z)
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

static size_t	update_map(t_map *map, mlx_image_t **img, size_t n)
{
	map->instance = n;
	map->img = img;

	return (map->instance);
}

void	load_static_image(t_win *sl, t_cat *cat)
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
			n = load(sl->mlx, cat->bckg, cnt, 0);
			update_map(&sl->map[cnt[H]][cnt[W]], &cat->bckg, n);
			//sl->map[cnt[H]][cnt[W]].instance = n;
			if (sl->map[cnt[H]][cnt[W]].c == '1')
			{
				n = load(sl->mlx, cat->wall, cnt, 1);
				update_map(&sl->map[cnt[H]][cnt[W]], &cat->wall, n);
			}
			else if (sl->map[cnt[H]][cnt[W]].c == 'C')
			{	
				n = load(sl->mlx, cat->item, cnt, 2);
				update_map(&sl->map[cnt[H]][cnt[W]], &cat->item, n);
			}
			cnt[W]++;
		}
		cnt[H]++;
	}
}

void	load_dynamic_image(t_win sl, t_anim *a, t_sprite *sprite)
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
				n = load_sprite(sl.mlx, sprite, a, cnt);
				if (n == 0)
					unexpected_close(ERR_SPRITE, &sl, sl.map);
				sl.map[cnt[H]][cnt[W]].instance = n;
			}
			cnt[W]++;
		}
		cnt[H]++;
	}
}
