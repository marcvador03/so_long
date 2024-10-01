/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:58:22 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/01 10:08:53 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_img(mlx_t *mlx, t_anim *a)
{
	size_t	i;

	i = 0;
	while (i < a->count)
		mlx_delete_image(mlx, a->img[i++]);
	free(a->img);
	free(a);	
}

static void	free_cat(mlx_t *mlx, t_cat *cat)
{
	free_img(mlx, cat->wall);
	free_img(mlx, cat->item);
	free_img(mlx, cat->exit);
	free_img(mlx, cat->hero);
	free_img(mlx, cat->bckg);
	free(cat);
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
	free_cat(sl->mlx, sl->cat);
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
	free_cat(sl->mlx, sl->cat);
	ft_printf("%s\n", "Error");
	ft_printf("%s\n", str);
	exit(1); //mlx_terminate??
}
