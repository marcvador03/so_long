/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:45:42 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 21:22:56 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	check_collision(t_map *map_adj, int32_t hero[5], int32_t move[2])
{
	int32_t	pos_adj[4];

	if (map_adj->c == '0')
		return (0);
	pos_adj[X] = map_adj->cur_a->img[0]->instances[map_adj->inst].x;
	pos_adj[Y] = map_adj->cur_a->img[0]->instances[map_adj->inst].y;
	pos_adj[X_W] = pos_adj[X] + map_adj->cur_a->img[0]->width;
	pos_adj[Y_H] = pos_adj[Y] + map_adj->cur_a->img[0]->height;
	if (move[X] > 0 && hero[X_W] + move[X] > pos_adj[X])
		return (map_adj->c);
	if (move[X] < 0 && hero[X] + move[X] < pos_adj[X_W])
		return (map_adj->c);
	if (move[Y] > 0 && hero[Y_H] + move[Y] > pos_adj[Y])
		return (map_adj->c);
	if (move[Y] < 0 && hero[Y] + move[Y] < pos_adj[Y_H])
		return (map_adj->c);
	return ('\0');
}

static t_map	*algo(t_win *sl, int32_t move[2], int32_t hero[5], int32_t i)
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
	else
	{
		x = (hero[X] + (i * PPT) + (move[X] / MOVE)) / PPT;
		y = (hero[Y_H] + (move[Y] / MOVE)) / PPT;
	}
	return (&sl->map[y][x]);
}

t_map	**identify_adj_map(t_win *sl, int32_t *move, int32_t *hero)
{
	t_map	**map_adj;
	int32_t	i;

	map_adj = (t_map **)ft_calloc(sizeof(t_map *), (map_len(move, hero) + 1));
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

static size_t	move_auth(t_win *sl, t_map **map_adj, int32_t *m, int32_t *h)
{
	int		i;
	char	c;

	i = 0;
	while (map_adj[i] != NULL)
	{
		c = check_collision(map_adj[i], h, m);
		if (c == '1')
			return (free(map_adj), free(m), free(h), 0);
		else if (c == 'C' && h[4] == 0)
		{
			collect_item(sl, sl->map, *map_adj[i]);
			return (free(map_adj), free(m), free(h), 1);
		}
		else if (c == 'E' && sl->item_cnt == 0)
			return (free(map_adj), free(m), free(h), 2);
		else if (c == 'M')
			return (free(map_adj), free(m), free(h), 3);
		i++;
	}
	return (free(map_adj), free(m), free(h), 1);
}

size_t	move_auth_init(t_win *sl, keys_t key, t_anim *a)
{
	int32_t	*hero;
	int32_t	*move;
	t_map	**map_adj;

	if (PPT < 0)
		unexpected_close(ERR_PPT, sl);
	hero = fill_coord(sl, a, key);
	move = fill_move(sl, a, key);
	map_adj = identify_adj_map(sl, move, hero);
	if (map_adj == NULL)
		unexpected_close(ERR_MALLOC, sl);
	return (move_auth(sl, map_adj, move, hero));
}
