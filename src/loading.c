/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:39:03 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 21:44:54 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_sprite(t_win *sl, mlx_t *mlx, t_sprite *s, t_anim *a)
{
	size_t	i;

	if (s == NULL || s->count <= 0 || a == NULL)
		unexpected_close(ERR_SPRITE, sl);
	a->img = (mlx_image_t **)ft_calloc(s->count, sizeof(mlx_image_t *));
	if (a->img == NULL)
		unexpected_close(ERR_MALLOC, sl);
	i = 0;
	while (i < s->count)
	{
		a->img[i] = mlx_texture_to_image(mlx, s->texture[i]);
		if (a->img[i] == NULL)
			unexpected_close(ERR_IMAGE, sl);
		if (mlx_resize_image(a->img[i], s->r_width, s->r_height) == false)
			unexpected_close(ERR_IMAGE_RES, sl);
		mlx_delete_texture(s->texture[i++]);
	}
	free(s->texture);
	a->count = s->count;
	return ;
}

void	attach_image(t_map *map, t_anim *a)
{
	if (map->cur_a == NULL && (ft_strncmp(a->name, "bckg", 4) != 0))
	{
		map->cur_a = a;
		map->inst = map->cur_a->img[0]->count - 1;
		map->cur_a->img[0]->instances[map->inst].enabled = true;
		map->cnt++;
	}
}

static void	load_img_loop(t_win *sl, t_anim *a, mlx_image_t *img, uint32_t p[4])
{
	size_t	n;

	p[X_W] = (p[W] * PPT) + (PPT - img->width);
	p[Y_H] = (p[H] * PPT) + (PPT - img->height);
	if (mlx_image_to_window(sl->mlx, img, p[X_W], p[Y_H]) == -1)
		unexpected_close(ERR_IMAGE, sl);
	n = img->count - 1;
	mlx_set_instance_depth(&img->instances[n], a->depth);
	img->instances[n].enabled = false;
}

static void	load_image(t_win *sl, t_map *map, t_anim *a, uint32_t p[4])
{
	size_t	i;
	size_t	n;

	i = 0;
	while (i < a->count)
		load_img_loop(sl, a, a->img[i++], p);
	n = a->img[0]->count - 1;
	if (map->cur_a == NULL && (ft_strncmp(a->name, "bckg", 4) != 0))
	{
		map->cur_a = a;
		if (map->c == 'P')
			sl->hero = a;
		map->inst = map->cur_a->img[0]->count - 1;
		map->cur_a->img[0]->instances[n].enabled = true;
		map->cnt++;
	}
	else if ((ft_strncmp(a->name, "bckg", 4)) == 0)
		a->img[0]->instances[n].enabled = true;
}

void	load_img_init(t_win *sl, t_anim *a, t_sprite *sprite, char c)
{
	uint32_t	cnt[4];
	t_map		*map;

	cnt[H] = 0;
	load_sprite(sl, sl->mlx, sprite, a);
	free(sprite);
	while (cnt[H] < sl->h_map)
	{
		cnt[W] = 0;
		while (cnt[W] < sl->w_map)
		{
			map = &sl->map[cnt[H]][cnt[W]];
			if (sl->map[cnt[H]][cnt[W]].c == c)
				load_image(sl, map, a, cnt);
			else if (ft_strncmp(a->name, "bckg", 4) == 0)
				load_image(sl, map, a, cnt);
			cnt[W]++;
		}
		cnt[H]++;
	}
	update_anim_frame(sl, a);
}
