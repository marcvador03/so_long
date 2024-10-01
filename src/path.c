/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:43:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/01 10:10:16 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_item(t_map map, uint32_t flag[3])
{
	if (map.c == 'P' && map.v == 1)
		flag[0] = flag[0] + 1;
	if (map.c == 'C' && map.v == 1)
		flag[1] = flag[1] + 1;
	if (map.c == 'E' && map.v == 1)
		flag[2] = flag[2] + 1;
}

char	*check_all_items(t_win *sl, t_map **map)
{
	unsigned int	h;
	unsigned int	w;
	uint32_t		*flag;

	h = 0;
	flag = (uint32_t *)ft_calloc(3, sizeof(uint32_t));
	if (flag == NULL)
		unexpected_close(ERR_MALLOC, sl, sl->map);
	while (h < sl->h_map)
	{
		w = 0;
		while (w < sl->w_map)
			check_item(map[h][w++], flag);
		h++;
	}
	if (flag[0] > 1 || flag[2] > 1)
		return (free(flag), ERR_MAP_DUP);
	if (flag[0] == 0)
		return (free(flag), ERR_MAP_HERO);
	if (flag[2] == 0)
		return (free(flag), ERR_MAP_EXIT);
	if (flag[1] != sl->item_cnt)
		return (free(flag), ERR_MAP_PATH);
	return (free(flag), NULL);
}

void	find_start_position(t_win *sl, t_map **map, uint32_t *h, uint32_t *w)
{
	*h = 0;
	while (*h < sl->h_map)
	{
		*w = 0;
		while (*w < sl->w_map)
		{
			if (map[*h][*w].c == 'P')
				return ;
			*w = *w + 1;
		}
		*h = *h + 1;
	}
}

void	check_path_loop(t_win *sl, t_map **map, uint32_t h, uint32_t w)
{
	if (w < sl->w_map && map[h][w + 1].c != '1' && map[h][w + 1].v != 1)
	{
		map[h][w].v = 1;
		check_path_loop(sl, map, h, w + 1);
	}
	if (h != 0 && map[h - 1][w].c != '1' && map[h - 1][w].v != 1)
	{
		map[h][w].v = 1;
		check_path_loop(sl, map, h - 1, w);
	}
	if (w != 0 && map[h][w - 1].c != '1' && map[h][w - 1].v != 1)
	{
		map[h][w].v = 1;
		check_path_loop(sl, map, h, w - 1);
	}
	if (h < sl->h_map && map[h + 1][w].c != '1' && map[h + 1][w].v != 1)
	{
		map[h][w].v = 1;
		check_path_loop(sl, map, h + 1, w);
	}
	return ;
}

void	check_path_init(t_win *sl, t_map **map)
{
	uint32_t	h;
	uint32_t	w;
	char		*error;

	find_start_position(sl, map, &h, &w);
	check_path_loop(sl, map, h, w);
	error = check_all_items(sl, map);
	if (error != NULL)
		unexpected_close(error, sl, sl->map);
}
