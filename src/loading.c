/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:39:03 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/01 18:19:16 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_sprite(mlx_t *mlx, t_sprite *s, t_anim *a)
{
	size_t	i;

	if (s == NULL || s->count <= 0 || a == NULL)
		return ;
	a->img = (mlx_image_t **)ft_calloc(s->count, sizeof(mlx_image_t *));
	if (a->img == NULL)
		return ;
	i = 0;
	while (i < s->count)
	{
		a->img[i] = mlx_texture_to_image(mlx, s->texture[i]);
		if (mlx_resize_image(a->img[i], s->r_width, s->r_height) == false)
			return ;
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

void	load_image(t_win *sl, t_map *map, t_anim *a, uint32_t p[2])
{
	size_t	i;
	size_t	n;
	
	i = 0;
	while (i < a->count)
	{
		mlx_image_to_window(sl->mlx, a->img[i], p[W] * PPT, p[H] * PPT);
		n = a->img[i]->count - 1;
		mlx_set_instance_depth(&a->img[i]->instances[n], a->depth);
		a->img[i++]->instances[n].enabled = false;
	}
	if (map->cur_a == NULL && (ft_strncmp(a->name, "bckg", 4) != 0))
	{
		map->cur_a = a;
		map->inst = map->cur_a->img[0]->count - 1;
		map->cur_a->img[0]->instances[n].enabled = true;
		map->cnt++;
	}
	else if ((ft_strncmp(a->name, "bckg", 4)) == 0)
		a->img[0]->instances[n].enabled = true;
}

void	load_image_init(t_win *sl, t_anim *a, t_sprite *sprite, char c)
{
	uint32_t	cnt[2];
	t_map		*map;

	cnt[H] = 0;
	load_sprite(sl->mlx, sprite, a);
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
			{
				load_image(sl, map, a, cnt);
			}
			cnt[W]++;
		}
		cnt[H]++;
	}
}
