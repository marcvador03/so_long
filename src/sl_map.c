/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:35:58 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/24 00:44:24 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	get_map_size(t_mainwindow *sl, char *path)
{
	char	*tmp;
	
	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		sl_close("error while opening file\n");
	tmp = get_next_line(sl->fd);
	sl->h_map = 0;
	sl->w_map = ft_strlen(tmp) - 1;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(sl->fd);
		if (tmp != NULL && sl->w_map != (int32_t)(ft_strlen(tmp) - 1))
			sl_close("map is not rectangular");
		sl->h_map++;
	}
	free(tmp);
	tmp = NULL;
	if (close(sl->fd) < 0)
		sl_close("error while closing fd");
}

static unsigned int	sl_line_fill(t_map *map, char *line)
{
	int				j;
	unsigned int	item_cnt;

	j = 0;
	item_cnt = 0;
	while (line[j] != '\n')
	{
		if (line[j] != '0' && line[j] != '1')
			if(line[j] !='C' && line[j] != 'E' && line[j] != 'P')
				sl_close("map check: forbidden value");
		map[j].c = line[j];
		if (line[j++] == 'C')
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
		sl_close("error while opening file\n");
	line = get_next_line(sl->fd);
	i = 0;
	sl->item_cnt = 0;
	sl->item_cnt += sl_line_fill(sl->map[i++], line);
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
		sl_close("error while closing fd");
}

void	sl_map_check_walls(t_map **map, unsigned int w, unsigned int h)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	while (j <= w)
		if (map[0][j].c != '1' || map[h][j++].c != '1')
			sl_close("map check: missing surrounding walls");
	i = 0;
	while (i <= h)
		if (map[i][0].c != '1' || map[i++][w].c != '1')
			sl_close("map check: missing surrounding walls");
}

void	sl_map_check_dups(t_map **map, unsigned int w, unsigned int h)
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
	if (cnt[0] > 1 || cnt[1] > 1) // yet missing cnt[2]==0 for collectibles	
		sl_close("map check: duplicate entry or start point");
}
