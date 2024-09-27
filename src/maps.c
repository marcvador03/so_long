/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:35:58 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/27 19:06:11 by mfleury          ###   ########.fr       */
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
	while (i < (sl->h_map)) //check for valgrind impact
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

static unsigned int	sl_line_fill(t_win *sl, t_map *map, char *line)
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
		map[i].v = 0;
		if (line[i++] == 'C')
			item_cnt++;
	}
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
	sl->item_cnt += sl_line_fill(sl, sl->map[i++], line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(sl->fd);
		if (line != NULL)
			sl->item_cnt += sl_line_fill(sl, sl->map[i++], line);
	}
	free(line);
	line = NULL;
	if (close(sl->fd) < 0)
		unexpected_close(ERR_CLOSE_FILE, sl, NULL);
}
