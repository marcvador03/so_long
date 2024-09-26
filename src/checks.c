/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:51:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/26 15:55:30 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_file_ext(t_win *sl, char *path)
{
	int		len;
	char	*str;

	if (path == NULL)
		unexpected_close(ERR_EXT, sl, sl->map);
	len = ft_strlen(path);
	str = ft_substr(path, len - 3, 3);
	if (str == NULL)
		unexpected_close(ERR_MALLOC, sl, sl->map);
	if (ft_strncmp(str, "ber", 3) != 0)
	{
		free(str);
		unexpected_close(ERR_EXT, sl, NULL);
	}
	free(str);
}

int	sl_map_check_walls(t_map **map, uint32_t w, uint32_t h)
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

int	sl_map_check_dups(t_map **map, unsigned int w, unsigned int h)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	flag[3];

	i = 0;
	j = 0;
	while (j <= 2)
		flag[j++] = 0;
	while (i <= h && (flag[0] <= 1 || flag[1] <= 1))
	{
		j = 0;
		while (j <= w)
		{
			if (map[i][j].c == 'E')
				flag[0]++;
			else if (map[i][j].c == 'P')
				flag[1]++;
			else if (map[i++][j++].c == 'C')
				flag[2]++;
		}
	}
	if (flag[0] > 1 || flag[1] > 1) // yet missing cnt[2]==0 for collectibles
		return (-1);
	return (0);
}
