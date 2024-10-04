/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:51:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 02:15:41 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_rect(t_win *sl, t_map **map)
{
	uint32_t	cnt[2];

	cnt[H] = 0;
	cnt[W] = 0;
	while (cnt[H] < sl->h_map)
	{
		if (map[cnt[H]][0].c != '1' || map[cnt[H]][sl->w_map - 1].c != '1')
			unexpected_close(ERR_MAP_NOT_RECT, sl);
		cnt[H]++;
	}
	while (cnt[W] < sl->w_map)
	{
		if (map[0][cnt[W]].c != '1' || map[sl->h_map - 1][cnt[W]].c != '1')
			unexpected_close(ERR_MAP_NOT_RECT, sl);
		cnt[W]++;
	}
}

static void	check_forbid_value(t_win *sl, t_map **map)
{
	uint32_t	cnt[2];
	t_map		m;

	cnt[H] = 0;
	cnt[W] = 0;
	while (cnt[H] < sl->h_map)
	{
		m = map[cnt[H]][cnt[W]];
		if (m.c > 0 && m.c <= 32)
			unexpected_close(ERR_FILE_EMPTY_LINE, sl);
		while (cnt[W] < sl->w_map)
		{
			m = map[cnt[H]][cnt[W]];
			if (m.c != '0' && m.c != '1' && m.c != 'C' && m.c != 'P')
				if (m.c != 'M' && m.c != 'E')
					unexpected_close(ERR_MAP_FORBID_VALUE, sl);
			cnt[W]++;
		}
		cnt[W] = 0;
		cnt[H]++;
	}
}

void	check_file_ext(t_win *sl, char *path)
{
	int		len;
	char	*str;

	if (path == NULL)
		unexpected_close(ERR_EXT, sl);
	len = ft_strlen(path);
	str = ft_substr(path, len - 3, 3);
	if (str == NULL)
		unexpected_close(ERR_MALLOC, sl);
	if (ft_strncmp(str, "ber", 3) != 0)
	{
		free(str);
		unexpected_close(ERR_EXT, sl);
	}
	free(str);
}

static void	check_walls(t_win *sl, t_map **map, uint32_t w, uint32_t h)
{
	uint32_t	i;
	uint32_t	j;

	j = 0;
	while (j < w)
		if (map[0][j].c != '1' || map[h - 1][j++].c != '1')
			unexpected_close(ERR_MAP_WALLS, sl);
	i = 0;
	while (i < h)
		if (map[i][0].c != '1' || map[i++][w - 1].c != '1')
			unexpected_close(ERR_MAP_WALLS, sl);
}

void	check_init(t_win *sl, t_map **map)
{
	check_rect(sl, map);
	check_forbid_value(sl, map);
	check_walls(sl, map, sl->w_map, sl->h_map);
	check_path_init(sl, map);
}
