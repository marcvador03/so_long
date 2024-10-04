/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:45:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 10:30:39 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	free_line_err(t_win *sl, char *line, char *error)
{
	free(line);
	unexpected_close(error, sl);
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

void	open_file(t_win *sl, char *path)
{
	check_file_ext(sl, path);
	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		unexpected_close(ERR_OPEN_FILE, sl);
}
