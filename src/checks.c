/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:51:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 16:30:08 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_forbid_value(t_win *sl, t_map **map)
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

int	map_check_walls(t_map **map, uint32_t w, uint32_t h)
{
	uint32_t	i;
	uint32_t	j;

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
