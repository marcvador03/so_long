/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:35:58 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/01 01:14:43 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	map_alloc(t_win *sl)
{
	size_t	i;

	i = 0;
	sl->map = (t_map **)ft_calloc(sl->h_map, sizeof(t_map *));
	if (sl->map == NULL)
		unexpected_close(ERR_MALLOC, sl, NULL);
	i = 0;
	sl->mem_count = 0;
	while (i < sl->h_map)
	{
		sl->map[i] = (t_map *)ft_calloc(sl->w_map, sizeof(t_map));
		if (sl->map[i] == NULL)
			unexpected_close(ERR_MALLOC, sl, sl->map);
		else
			sl->mem_count++;
		i++;
	}
}

void	get_map_size(t_win *sl, char *path)
{
	char	*tmp;

	check_file_ext(sl, path);
	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		unexpected_close(ERR_OPEN_FILE, sl, NULL);
	tmp = get_next_line(sl->fd);
	sl->h_map = 0;
	sl->w_map = (uint32_t)(ft_strlen(tmp) - 1);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(sl->fd);
		if (tmp != NULL && sl->w_map != (uint32_t)(ft_strlen(tmp) - 1))
			unexpected_close(ERR_MAP_NOT_RECT, sl, NULL);
		sl->h_map++ ;
	}
	free(tmp);
	tmp = NULL;
	if (close(sl->fd) < 0)
		unexpected_close(ERR_CLOSE_FILE, sl, NULL);
}

static unsigned int	sl_line_fill(t_win *sl, t_map *map, char *line, int32_t *y)
{
	int32_t		i;
	uint32_t	item_cnt;

	i = 0;
	item_cnt = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1')
			if (line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
				unexpected_close(ERR_MAP_FORBID_VALUE, sl, NULL);
		map[i].c = line[i];
		map[i].x = i;
		map[i].y = *y;
		if (line[i] == 'P')
		{
			sl->h_hero = *y;
			sl->w_hero = i;
		}		
		if (line[i++] == 'C')
			item_cnt++;
	}
	*y = *y + 1;
	return (item_cnt);
}

void	sl_map_fill(t_win *sl, char *path)
{
	char	*line;
	int		i;

	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		unexpected_close(ERR_OPEN_FILE, sl, NULL);
	line = get_next_line(sl->fd);
	i = 0;
	sl->item_cnt = 0;
	sl->item_cnt += sl_line_fill(sl, sl->map[i], line, &i);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(sl->fd);
		if (line != NULL)
			sl->item_cnt += sl_line_fill(sl, sl->map[i], line, &i);
	}
	free(line);
	line = NULL;
	if (close(sl->fd) < 0)
		unexpected_close(ERR_CLOSE_FILE, sl, NULL);
}

int32_t	map_len(int32_t move[2], int32_t hero[4])
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
