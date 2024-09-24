/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:35:58 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/24 23:39:05 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	map_alloc(t_mainwindow *sl)
{
	size_t	i;

	i = 0;
	sl->map = (t_map **)ft_calloc(sl->h_map, sizeof(t_map *));
	if (sl->map == NULL)
		unexpected_close(ERR_MALLOC, sl->slx, NULL);	
	i = 0;
	sl->map[i]->mem_count = 0;
	while (i <= (sl->h_map)) //check for valgrind impact
	{
		sl->map[i] = (t_map *)ft_calloc(sl->w_map, sizeof(t_map));
		if (sl->map[i] == NULL)
			unexpected_close(ERR_MALLOC, sl->slx, sl->map);
		else
			sl->map[i]->mem_count++;
		i++;	
	}
	sl->map[i] = NULL;
}

void	get_map_size(t_mainwindow *sl, char *path)
{
	char	*tmp;
	
	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		unexpected_close(ERR_OPEN_FILE, sl->slx, NULL);	
	tmp = get_next_line(sl->fd);
	sl->h_map = 0;
	sl->w_map = (uint32_t)(ft_strlen(tmp) - 1);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(sl->fd);
		if (tmp != NULL && sl->w_map != (uint32_t)(ft_strlen(tmp) - 1))
			unexpected_close(ERR_MAP_NOT_RECT, sl->slx, NULL);	
		sl->h_map++ ;
	}
	free(tmp);
	tmp = NULL;
	if (close(sl->fd) < 0)
		unexpected_close(ERR_CLOSE_FILE, sl->slx, NULL);	
}

static unsigned int	sl_line_fill(t_map *map, char *line)
{
	int32_t		i;
	uint32_t	item_cnt;

	i = 0;
	item_cnt = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1')
			if(line[i] !='C' && line[i] != 'E' && line[i] != 'P')
				return (0);
		map[i].c = line[i];
		if (line[i++] == 'C')
			item_cnt++;
	}
	return (item_cnt);
}

void	sl_map_fill(t_mainwindow *sl, char *path)
{
	char	*line;
	int		i;

	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		unexpected_close(ERR_OPEN_FILE, sl->slx, NULL);	
	line = get_next_line(sl->fd);
	i = 0;
	sl->item_cnt = 0;
	sl->item_cnt += sl_line_fill(sl->map[i++], line);
	if (sl->item_cnt == 0)
		unexpected_close(ERR_MAP_FORBID_VALUE, sl->slx, NULL);	
	while (line != NULL)
	{
		free(line);
		line = get_next_line(sl->fd);
		if (line != NULL)
			sl->item_cnt += sl_line_fill(sl->map[i++], line);
	}
	free(line);
	line = NULL;
	if (close(sl->fd) < 0)
		unexpected_close(ERR_CLOSE_FILE, sl->slx, NULL);	
}

int	sl_map_check_walls(t_map **map, uint32_t w, uint32_t h)
{
	uint32_t	i;
	uint32_t	 j;

	j = 0;
	while (j <= w)
		if (map[0][j].c != '1' || map[h][j++].c != '1')
			return (-1);
	i = 0;
	while (i <= h)
		if (map[i][0].c != '1' || map[i++][w].c != '1')
			return (-1);
	return (0);
}

int	sl_map_check_dups(t_map **map, unsigned int w, unsigned int h)
{
	unsigned int i;
	unsigned int j;
	unsigned int cnt[3];

	i = 0;
	j = 0;
	while (j <= 2)
		cnt[j++] = 0;
	while (i <= h && (cnt[0] <= 1 || cnt[1] <= 1))
	{
		j = 0;
		while (j <= w)
		{
			if (map[i][j].c == 'E')
				cnt[0]++;
			else if (map[i][j].c == 'P')
				cnt[1]++;
			else if (map[i][j].c == 'C')
				cnt[2]++;
			j++;
		}
		i++;
	}
	if (cnt[0] > 1 || cnt[1] > 1)	// yet missing cnt[2]==0 for collectibles	
		return (-1);
	return (0);
}
