/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:37:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/26 19:36:01 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static int	check_collision(t_map *map_adj, int32_t hero[4], int32_t move[2])
{
	int32_t	pos_adj[4];

	if (map_adj->c != '1')
		return (0);
	pos_adj[X] = map_adj->img[0]->instances[map_adj->instance].x;
	pos_adj[Y] = map_adj->img[0]->instances[map_adj->instance].y;
	pos_adj[X_W] = pos_adj[X] + map_adj->img[0]->width;
	pos_adj[Y_H] = pos_adj[Y] + map_adj->img[0]->height;
	if (move[X] > 0 && hero[X_W] + move[X] > pos_adj[X])
		return (1);
	if (move[X] < 0 && hero[X] + move[X] < pos_adj[X_W])
		return (1);
	if (move[Y] > 0 && hero[Y_H] + move[Y] > pos_adj[Y])
		return (1);
	if (move[Y] < 0 && hero[Y] + move[Y] < pos_adj[Y_H])
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

static t_map **identify_adj_map(t_win *sl, int32_t move[2], int32_t hero[4])
{
	t_map	**map_adj;
	int32_t	len;
	int32_t i;
	int		x;
	int		y;

	if (move[X] != 0)
		len = hero[X_W] - hero[X];
	else if (move[Y] != 0)
		len = hero[Y_H] - hero[Y];
	else
		return (NULL);
	map_adj = (t_map **)malloc(sizeof(t_map *) * (len + 1));
	if (map_adj == NULL)	
		return (NULL);
	i = 0;
	while (i < len)
	{
		x = (hero[X] / PPT) + (i * PPT) + (move[Y] / MOVE);
		y = (hero[Y] / PPT) + (i * PPT) + (move[X] / MOVE);
		map_adj[i] = &sl->map[y][x];
		i++;
	}
	map_adj[i] = NULL;
	return (map_adj);

}
static size_t	move_auth(t_win *sl, t_cat *cat, keys_t key, mlx_image_t **img)
{
	int		i;
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
	i = 0;
	while (map_adj[i] != NULL)
	{
		if (check_collision(map_adj[i], hero, move) == 1)
			return (0);
		free(map_adj[i++]);
	}
	return (free(map_adj[i]), free(map_adj), move_hero(cat->h_idle, cat->h_run, move));
}
