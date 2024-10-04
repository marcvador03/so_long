/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:35:58 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 02:15:41 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	map_alloc(t_win *sl)
{
	size_t	i;

	i = 0;
	sl->map = (t_map **)ft_calloc(sl->h_map, sizeof(t_map *));
	if (sl->map == NULL)
		unexpected_close(ERR_MALLOC, sl);
	i = 0;
	while (i < sl->h_map)
	{
		sl->map[i] = (t_map *)ft_calloc(sl->w_map, sizeof(t_map));
		if (sl->map[i] == NULL)
			unexpected_close(ERR_MALLOC, sl);
		else
			sl->map_cnt++;
		i++;
	}
}

void	get_map_size(t_win *sl, char *path)
{
	char	*tmp;

	check_file_ext(sl, path);
	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		unexpected_close(ERR_OPEN_FILE, sl);
	tmp = get_next_line(sl->fd);
	if (tmp == NULL)
		free_line_err(sl, tmp, ERR_FILE_EMPTY);
	sl->w_map = (uint32_t)(ft_strlen(tmp) - 1);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(sl->fd);
		/*if (tmp != NULL && tmp[0] == '\n')
			free_line_err(sl, tmp, ERR_FILE_EMPTY_LINE);
		if (tmp != NULL && sl->w_map != (uint32_t)(ft_strlen(tmp) - 1))
			free_line_err(sl, tmp, ERR_MAP_NOT_RECT);*/
		sl->h_map++;
	}
	free(tmp);
	tmp = NULL;
	if (close(sl->fd) < 0)
		unexpected_close(ERR_CLOSE_FILE, sl);
}

static uint32_t	line_fill(t_map *map, char *line, int32_t *y)
{
	int32_t		i;
	uint32_t	item_cnt;

	i = 0;
	item_cnt = 0;
	while (line[i] != '\n')
	{
	/*	if (line[i] != '0' && line[i] != '1' && line[i] != 'M')
			if (line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
				free_line_err(sl, line, ERR_MAP_FORBID_VALUE);
				//unexpected_close(ERR_MAP_FORBID_VALUE, sl);*/
		map[i].c = line[i];
		map[i].x = i;
		map[i].y = *y;
		if (line[i++] == 'C')
			item_cnt++;
	}
	*y = *y + 1;
	return (item_cnt);
}

void	map_fill(t_win *sl, char *path)
{
	char	*line;
	int		i;

	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		unexpected_close(ERR_OPEN_FILE, sl);
	line = get_next_line(sl->fd);
	i = 0;
	sl->item_cnt = 0;
	sl->item_cnt += line_fill(sl->map[i], line, &i);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(sl->fd);
		if (line != NULL)
			sl->item_cnt += line_fill(sl->map[i], line, &i);
	}
	free(line);
	line = NULL;
	if (close(sl->fd) < 0)
		unexpected_close(ERR_CLOSE_FILE, sl);
}
