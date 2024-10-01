/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:58:22 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/01 14:51:20 by mfleury          ###   ########.fr       */
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
	free_img(mlx, cat->item_c);
	free_img(mlx, cat->exit);
	free_img(mlx, cat->hero);
	free_img(mlx, cat->bckg);
	free_img(mlx, cat->item_o);
	free(cat);
}

void	esc_close(t_win *sl, t_map **map)
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
	mlx_terminate(sl->mlx);
	exit(1);
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
	//mlx_delete_image(sl->mlx, sl->s_cnt);
	mlx_delete_image(sl->mlx, sl->str_move);
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
	free(sl->map);
	free_cat(sl->mlx, sl->cat);
	mlx_delete_image(sl->mlx, sl->str_move);
	ft_printf("%s\n", "Error");
	ft_printf("%s\n", str);
	mlx_terminate(sl->mlx);
	exit(1);
}
