/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:35:58 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 14:17:55 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"
void	free_line_err(t_win *sl, char *line, char *error)
{
	free(line);
	unexpected_close(error, sl);

}
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
	if (tmp == NULL || tmp[0] == '\n')
		free_line_err(sl, tmp, ERR_FILE_EMPTY_LINE);
	sl->w_map = (uint32_t)(ft_strlen(tmp) - 1);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(sl->fd);
		if (tmp == NULL || tmp[0] == '\n')
			free_line_err(sl, tmp, ERR_FILE_EMPTY_LINE);
		if (tmp != NULL && sl->w_map != (uint32_t)(ft_strlen(tmp) - 1))
			free_line_err(sl, tmp, ERR_MAP_NOT_RECT);
		sl->h_map++ ;
	}
	free(tmp);
	tmp = NULL;
	if (close(sl->fd) < 0)
		unexpected_close(ERR_CLOSE_FILE, sl);
}

static unsigned int	sl_line_fill(t_win *sl, t_map *map, char *line, int32_t *y)
{
	int32_t		i;
	uint32_t	item_cnt;

	i = 0;
	item_cnt = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'M')
			if (line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
				unexpected_close(ERR_MAP_FORBID_VALUE, sl);
		map[i].c = line[i];
		map[i].x = i;
		map[i].y = *y;
		/*if (line[i] == 'P')
		{
			sl->h_hero = *y;
			sl->w_hero = i;
		}*/		
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
		unexpected_close(ERR_OPEN_FILE, sl);
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
		unexpected_close(ERR_CLOSE_FILE, sl);
}

int32_t	map_len(int32_t move[2], int32_t hero[5])
{
	int32_t	len;

	len = 0;
	if (move[X] != 0)
	{
		if ((hero[Y_H] - hero[Y]) >= PPT && hero[Y] % PPT != 0)
			len = ((hero[Y_H] - hero[Y]) / PPT) + 1;
		else
			len = 1;
	}
	else if (move[Y] != 0)
	{
		if ((hero[X_W] - hero[X]) >= PPT && hero[X] % PPT != 0)
			len = ((hero[X_W] - hero[X]) / PPT) + 1;
		else
			len = 1;
	}
	else
		return (0);
	return (len);
}
