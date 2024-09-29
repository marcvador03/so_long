/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:58:22 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/29 18:03:24 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_img(t_cat *cat)
{
	size_t	i;

	i = 0;
	while (i < cat->h_idle_s->count)
		mlx_delete_texture(cat->h_idle_s->texture[i++]);
	free(cat->h_idle_s->texture);
	free(cat->h_idle_s);
	free(cat->h_idle->img);
	free(cat->h_idle);
	free(cat->h_run->img);
	free(cat->h_run);
	free(cat->h_dead->img);
	free(cat->h_dead);
}

void	exp_close(void *ptr)
{
	t_win	*sl;
	size_t	i;

	sl = (t_win *)ptr;
	i = 0;
	while (i < sl->mem_count)
		free(sl->map[i++]);
	free(sl->map);
	//free(sl->cat);
}

void	unexpected_close(char *str, t_win *sl, t_map **map)
{
	size_t	i;

	i = 0;
	if (map != NULL)
	{
		while (i < sl->mem_count)
			free(map[i++]);
		free(map);
	}
	//free(sl->cat);
	ft_printf("%s\n", "Error");
	ft_printf("%s\n", str);
	exit(1); //mlx_terminate??
}
