/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:37:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/27 15:52:34 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static int32_t	map_len(int32_t move[2], int32_t hero[4])
{
	int32_t	len;
	int32_t	n;

	len = 0;
	n = 0;
	if (move[X] != 0)
	{
		if ((hero[Y_H] - hero[Y]) >= PPT && hero[Y] % PPT != 0)
			n = 1;
		len = ((hero[Y_H] - hero[Y]) / PPT) + n;
	}
	else if (move[Y] != 0)
	{
		if ((hero[X_W] - hero[X]) >= PPT && hero[X] % PPT != 0)
			n = 1;
		len = ((hero[X_W] - hero[X]) / PPT) + n;
	}
	else
		return (0);
	return (len);
}

static t_map	*algo(t_win *sl, int32_t move[2], int32_t hero[4], int32_t i)
{
	int		x;
	int		y;

	if (move[Y] < 0)
	{
		x = (hero[X] + (i * PPT) + (move[X] / MOVE)) / PPT;
		y = (hero[Y] + (move[Y] / MOVE)) / PPT;
	}
	else if (move[X] < 0)
	{
		x = (hero[X] + (move[X] / MOVE)) / PPT;
		y = (hero[Y] + (i * PPT) + (move[Y] / MOVE)) / PPT;
	}
	else if (move[X] > 0)
	{
		x = (hero[X_W] + (move[X] / MOVE)) / PPT;
		y = (hero[Y] + (i * PPT) + (move[Y] / MOVE)) / PPT;
	}
	else if (move[Y] > 0)
	{
		x = (hero[X] + (i * PPT) + (move[X] / MOVE)) / PPT;
		y = (hero[Y_H] + (move[Y] / MOVE)) / PPT;
	}
	return (&sl->map[y][x]);
}

static t_map	**identify_adj_map(t_win *sl, int32_t move[2], int32_t hero[4])
{
	t_map	**map_adj;
	int32_t	i;

	map_adj = (t_map **)malloc(sizeof(t_map *) * (map_len(move, hero) + 1));
	if (map_adj == NULL || (move[Y] == 0 && move[X] == 0))
		return (NULL);
	i = 0;
	while (i < map_len(move, hero))
	{
		map_adj[i] = algo(sl, move, hero, i);
		i++;
	}
	map_adj[i] = NULL;
	return (map_adj);
}

size_t	move_auth(t_map **map_adj, t_cat *cat, int32_t move[2], int32_t hero[4])
{
	int	i;

	i = 0;
	while (map_adj[i] != NULL)
	{
		if (check_collision(map_adj[i++], hero, move) == 1)
			return (0);
	}
	return (free(map_adj), move_hero(cat->h_idle, cat->h_run, move));
}

size_t	move_init(t_win *sl, t_cat *cat, keys_t key, mlx_image_t **img)
{
	int32_t	hero[4];
	int32_t	move[2];
	t_map	**map_adj;

	if (PPT < 0)
		unexpected_close(ERR_PPT, sl, sl->map);
	move[X] = 0;
	move[Y] = 0;
	hero[X] = img[0]->instances[0].x;
	hero[Y] = img[0]->instances[0].y;
	hero[X_W] = hero[X] + img[0]->width;
	hero[Y_H] = hero[Y] + img[0]->height;
	if (key == MLX_KEY_RIGHT)
		move[X] = MOVE;
	if (key == MLX_KEY_LEFT)
		move[X] = -MOVE;
	if (key == MLX_KEY_UP)
		move[Y] = -MOVE;
	if (key == MLX_KEY_DOWN)
		move[Y] = MOVE;
	map_adj = identify_adj_map(sl, move, hero);
	if (map_adj == NULL)
		unexpected_close(ERR_MALLOC, sl, sl->map);
	return (move_auth(map_adj, cat, move, hero));
}
