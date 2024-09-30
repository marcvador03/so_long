/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 21:00:21 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_anim	*create_anime(double fps, int32_t x_move, int32_t y_move, int32_t z)
{
	t_anim	*anime;

	anime = (t_anim *)ft_calloc(sizeof(t_anim), 1);
	if (anime == NULL)
		return (NULL);
	anime->fps = fps;
	anime->x_move = x_move;
	anime->y_move = y_move;
	anime->depth = z;
	anime->count = 0;
	anime->frame = 0;
	anime->img = NULL;
	return (anime);
}

void	anime_sprite(void *ptr)
{
	double	time[2];
	t_anim	*anime;
	int		i;

	anime = (t_anim *)ptr;
	if (anime->enabled == false)
		return ;
	i = anime->frame;
	time[0] = mlx_get_time();
	time[1] = time[0];
	while ((time[1] - anime->fps) <= time[0])
		time[1] = mlx_get_time();
	anime->img[i]->instances[0].enabled = true;
	if (i == 0 && anime->count > 1)
		anime->img[anime->count - 1]->instances[0].enabled = false;
	else if (anime->count > 1)
		anime->img[i - 1]->instances[0].enabled = false;
	anime->img[i]->instances[0].x += anime->x_move;
	anime->img[i]->instances[0].y += anime->y_move;
	anime->frame = (anime->frame + 1) % anime->count;
}
