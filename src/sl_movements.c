/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:37:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/26 13:01:00 by mfleury          ###   ########.fr       */
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

static size_t	sl_move_authorized(t_mainwindow *sl, keys_t key, mlx_image_t **img)
{
	size_t	n;
	int32_t	pix[4];
	int32_t	move[2];
	t_map	map_adj;
	
	if (PPT < 0)
		unexpected_close(ERR_PPT, sl, sl->map);
	n = 0;
	move[X] = 0;
	move[Y] = 0;
	pix[X] = img[0]->instances[0].x;
	pix[Y] = img[0]->instances[0].y;
	pix[XBIS] = pix[X] + img[0]->width;
	pix[YBIS] = pix[Y] + img[0]->height;
	if (key == MLX_KEY_RIGHT)
	{
		move[X] = MOVE;
		map_adj = sl->map[pix[Y] / PPT][(pix[X] / PPT) + 1]; //toher collistion check to be done with pix[YBIS] and pix[XBIS]
		if (check_collision(map_adj, pix, move) == 0)
		{
			map_adj = sl->map[pix[YBIS] / PPT][(pix[X] / PPT) + 1]; //toher collistion check to be done with pix[YBIS] and pix[XBIS]
			if (check_collision(map_adj, pix, move) == 0)
				n = move_hero(sl->hero_idle, sl->hero_run, move);
				//img[0]->instances[n++].x += MOVE;
		}

	}
	if (key == MLX_KEY_LEFT)
	{
		move[X] = - MOVE;
		map_adj = sl->map[pix[Y] / PPT][(pix[X] / PPT) - 1];
		if (check_collision(map_adj, pix, move) == 0)
		{
			map_adj = sl->map[pix[YBIS] / PPT][(pix[X] / PPT) - 1];
			if (check_collision(map_adj, pix, move) == 0)
				n = move_hero(sl->hero_idle, sl->hero_run, move);
		}
	}
	if (key == MLX_KEY_UP)
	{
		move[Y] = - MOVE;
		map_adj = sl->map[(pix[Y] / PPT) - 1][pix[X] / PPT];
		if (check_collision(map_adj, pix, move) == 0)
		{
			map_adj = sl->map[(pix[Y] / PPT) - 1][pix[XBIS] / PPT];
			if (check_collision(map_adj, pix, move) == 0)
				n = move_hero(sl->hero_idle, sl->hero_run, move);
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
				n = move_hero(sl->hero_idle, sl->hero_run, move);
		}
	}
	return (n);	
}

static void	sl_move_action(t_mainwindow *sl, mlx_image_t **img)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	if (PPT < 0)
		unexpected_close(ERR_PPT, sl, sl->map);
	i = img[0]->instances[0].y / PPT;
	j = img[0]->instances[0].x / PPT;
	if (sl->map[i][j].c == 'C')
	{
		n = sl->map[i][j].instance;
		sl->item->instances[n].enabled = false;
		sl->map[i][j].c = '0';
		sl->item_cnt--;
	}
	if (sl->map[i][j].c == 'E' && sl->item_cnt == 0)
		exp_close(&sl) ;//how to call success?
}

void	sl_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mainwindow *sl;
	size_t		n;

	sl = (t_mainwindow *)param;
	/*if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exp_close(sl);*/
	if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		{
			n = sl_move_authorized(sl, keydata.key, sl->hero_idle->img);
			if (n > 0)
			{
				sl->move_cnt += n;
				ft_printf("Current #movements: %d\n", sl->move_cnt);
				activate(sl->hero_idle, 0);
				de_activate(sl->hero_run, 0);
				sl_move_action(sl, sl->hero_idle->img);
			}
		}
}
