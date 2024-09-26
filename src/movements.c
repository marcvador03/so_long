/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:37:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/26 17:02:57 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static int	check_collision(t_map map_adj, int32_t pos_hero[4], int32_t move[2])
{
	int32_t	pos_adj[4];

	if (map_adj.c != '1')
		return (0);
	pos_adj[X] = map_adj.img[0]->instances[map_adj.instance].x;
	pos_adj[Y] = map_adj.img[0]->instances[map_adj.instance].y;
	pos_adj[XBIS] = pos_adj[X] + map_adj.img[0]->width;
	pos_adj[YBIS] = pos_adj[Y] + map_adj.img[0]->height;
	if (move[X] > 0 && pos_hero[XBIS] + move[X] >= pos_adj[X])
		return (1);
	if (move[X] < 0 && pos_hero[X] + move[X] < pos_adj[XBIS])
		return (1);
	if (move[Y] > 0 && pos_hero[YBIS] + move[Y] >= pos_adj[Y])
		return (1);
	if (move[Y] < 0 && pos_hero[Y] + move[Y] < pos_adj[YBIS])
		return (1);
	return (0);
}

static size_t	move_hero(t_anim *idle, t_anim *run, int32_t move[2])
{
	size_t	i;

	i = 0;
	de_activate(idle, 0);
	activate(run, 0);
	while (i < idle->count)
	{
		idle->img[i]->instances[0].x += move[X];
		idle->img[i++]->instances[0].y += move[Y];
	}
	i = 0;
	while (i < run->count)
	{
		run->img[i]->instances[0].x += move[X];
		run->img[i++]->instances[0].y += move[Y];
	}
	return (1);
}

/*static size_t	check_move(t_win *sl, int32_t pix[4], int32_t move[2])
{		
	t_map	map_adj;
	
	move[X] = MOVE;
	map_adj = sl->map[pix[Y] / PPT][(pix[X] / PPT) + 1]; //toher collistion check to be done with pix[YBIS] and pix[XBIS]
	if (check_collision(map_adj, pix, move) == 0)
	{
		map_adj = sl->map[pix[YBIS] / PPT][(pix[X] / PPT) + 1]; //toher collistion check to be done with pix[YBIS] and pix[XBIS]
		if (check_collision(map_adj, pix, move) == 0)
			n = move_hero(sl->cat->h_idle, sl->cat->h_run, move);
}*/

static t_map **identify_adj_map(t_win *sl, int32_t move[2])
{
	t_map	**map_adj;
	int32_t	len;
	int32_t i;

	if (move[X] != 0)
		len = prot[X_W] - prot[X];
	else if (move[Y] != 0)
		len = prot[Y_W] - prot[Y];
	else
		return;
	map_adj = (t_map **)malloc(sizeof(t_map *) * len);
	if (map_adj == NULL)
		unexpected_close(ERR_MALLOC, sl, sl->map);
	i = 0;
	x = (prot[X] / PPT) + (i * PPT) + (move[Y] / MOVE);
	y = (prot[Y] / PPT) + (i * PPT) + (move[X] / MOVE);
	while (i < len)
	{
		map_adj[i] = sl->map[y][x];
		i++;
	}
	return (map_adj);

}
static size_t	sl_move_authorized(t_win *sl, t_cat *cat, keys_t key, mlx_image_t **img)
{
	size_t	n;
	int32_t	pix[4];
	int32_t	move[2];

	if (PPT < 0)
		unexpected_close(ERR_PPT, sl, sl->map);
	n = 0;
	move[X] = 0;
	move[Y] = 0;
	pix[X] = img[0]->instances[0].x;
	pix[Y] = img[0]->instances[0].y;
	pix[X_W] = pix[X] + img[0]->width;
	pix[Y_Y] = pix[Y] + img[0]->height;
	if (key == MLX_KEY_RIGHT)
	{
		move[X] = MOVE;
		//img[0]->instances[n++].x += MOVE;
	}
	if (key == MLX_KEY_LEFT)
	{
		move[X] = -MOVE;
		map_adj = sl->map[pix[Y] / PPT][(pix[X] / PPT) - 1];
		if (check_collision(map_adj, pix, move) == 0)
		{
			map_adj = sl->map[pix[YBIS] / PPT][(pix[X] / PPT) - 1];
			if (check_collision(map_adj, pix, move) == 0)
				n = move_hero(cat->h_idle, cat->h_run, move);
		}
	}
	if (key == MLX_KEY_UP)
	{
		move[Y] = -MOVE;
		map_adj = sl->map[(pix[Y] / PPT) - 1][pix[X] / PPT];
		if (check_collision(map_adj, pix, move) == 0)
		{
			map_adj = sl->map[(pix[Y] / PPT) - 1][pix[XBIS] / PPT];
			if (check_collision(map_adj, pix, move) == 0)
				n = move_hero(cat->h_idle, cat->h_run, move);
		}
	}
	if (key == MLX_KEY_DOWN)
	{
		move[Y] = MOVE;
		map_adj = sl->map[(pix[Y] / PPT) + 1][pix[X] / PPT];
		if (check_collision(map_adj, pix, move) == 0)
		{
			map_adj = sl->map[(pix[Y] / PPT) + 1][pix[XBIS] / PPT];
			if (check_collision(map_adj, pix, move) == 0)
				n = move_hero(cat->h_idle, cat->h_run, move);
		}
	}
	return (n);
}
