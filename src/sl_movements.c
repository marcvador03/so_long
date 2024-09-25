/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:37:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/25 10:31:34 by mfleury          ###   ########.fr       */
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
static size_t	sl_move_authorized(t_mainwindow *sl, keys_t key)
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
	pix[X] = sl->hero->instances[0].x;
	pix[Y] = sl->hero->instances[0].y;
	pix[XBIS] = pix[X] + sl->hero->width;
	pix[YBIS] = pix[Y] + sl->hero->height;
	if (key == MLX_KEY_RIGHT)
	{
		move[X] = MOVE;
		map_adj = sl->map[pix[Y] / PPT][(pix[X] / PPT) + 1]; //toher collistion check to be done with pix[YBIS] and pix[XBIS]
		if (check_collision(map_adj, pix, move) == 0)
		{
			map_adj = sl->map[pix[YBIS] / PPT][(pix[X] / PPT) + 1]; //toher collistion check to be done with pix[YBIS] and pix[XBIS]
			if (check_collision(map_adj, pix, move) == 0)
				sl->hero->instances[n++].x += MOVE;
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
				sl->hero->instances[n++].x -= MOVE;
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
				sl->hero->instances[n++].y -= MOVE;
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
				sl->hero->instances[n++].y += MOVE;
		}
	}
	return (n);	
}
/*static size_t	sl_move_authorized(t_mainwindow *sl, keys_t key)
{
	int32_t	px[2];
	int32_t	ps[2];
	size_t	n;

	if (PPT < 0)
		sl_close("Error in pixel per tile PPT definition");
	n = 0;
	px[H] = sl->hero->instances[0].y;
	px[W] = sl->hero->instances[0].x;
	ps[H] = sl->hero->instances[0].y / PPT;
	ps[W] = sl->hero->instances[0].x / PPT;
	if (key == MLX_KEY_RIGHT && (px[W] + sl->hero->width) < (sl->w_map * PPT))
		if (sl->map[ps[H]][(px[W] + sl->hero->width) / PPT].c != '1')
			sl->hero->instances[n++].x += 1;
	if (key == MLX_KEY_LEFT && px[W] > 0)
		if (sl->map[ps[H]][ps[W]].c != '1')
			sl->hero->instances[n++].x -= 1;
	if (key == MLX_KEY_UP && px[H] > 0)
		if (sl->map[ps[H]][ps[W]].c != '1')
			sl->hero->instances[n++].y -= 1;
	if (key == MLX_KEY_DOWN && (px[H] + sl->hero->height) < (sl->h_map * PPT))
		if (sl->map[(px[H] + sl->hero->height) / PPT][ps[W]].c != '1')
			sl->hero->instances[n++].y += 1;
	return (n);	
}*/

/*static size_t	sl_move_authorized(t_mainwindow *sl, keys_t key)
{
	int32_t	i;
	int32_t	j;
	size_t	n;

	n = 0;
	if (PPT < 0)
		sl_close("Error in pixel per tile PPT definition");
	i = sl->hero->instances[0].y / PPT;
	j = sl->hero->instances[0].x / PPT;
	if (key == MLX_KEY_RIGHT && j < sl->w_map)
		if (sl->map[i][j + 1].c != '1')
			sl->hero->instances[n++].x += PPT;
	if (key == MLX_KEY_LEFT && j > 0)
		if (sl->map[i][j - 1].c != '1')
			sl->hero->instances[n++].x -= PPT;
	if (key == MLX_KEY_UP && i > 0)
		if (sl->map[i - 1][j].c != '1')
			sl->hero->instances[n++].y -= PPT;
	if (key == MLX_KEY_DOWN && i < sl->h_map)
		if (sl->map[i + 1][j].c != '1')
			sl->hero->instances[n++].y += PPT;
	return (n);	
}*/


static void	sl_move_action(t_mainwindow *sl)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	if (PPT < 0)
		unexpected_close(ERR_PPT, sl, sl->map);
	i = sl->hero->instances[0].y / PPT;
	j = sl->hero->instances[0].x / PPT;
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
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exp_close(&sl);
	if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		{
			n = sl_move_authorized(sl, keydata.key);
			if (n > 0)
			{
				sl->move_cnt += n;
				ft_printf("Current #movements: %d\n", sl->move_cnt);
				sl_move_action(sl);
			}
		}
}
