/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:58:22 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 01:57:03 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_img(mlx_t *mlx, t_anim *a)
{
	size_t	i;

	i = 0;
	while (i < a->count)
	{
		mlx_delete_image(mlx, a->img[i]);
		free(a->frame[i++]);
	}
	free(a->frame);
	free(a->img);
	free(a);
}

void	free_cat(mlx_t *mlx, t_cat *cat)
{
	free_img(mlx, cat->wall);
	free_img(mlx, cat->item_c);
	free_img(mlx, cat->exit);
	free_img(mlx, cat->bckg);
	free_img(mlx, cat->hero_idle);
	free_img(mlx, cat->hero_idle_m);
	free_img(mlx, cat->item_o);
	free_img(mlx, cat->mush);
	free_img(mlx, cat->mons);
	free_img(mlx, cat->mons_dead);
	free_img(mlx, cat->arrow_up);
	free_img(mlx, cat->arrow_down);
	free_img(mlx, cat->arrow_r);
	free_img(mlx, cat->arrow_l);
	free(cat);
}

void	free_map(t_win *sl)
{
	size_t	i;

	i = 0;
	while (i < sl->map_cnt)
		free(sl->map[i++]);
	free(sl->map);
}

void	esc_close(t_win *sl, t_map **map)
{
	size_t	i;

	i = 0;
	if (map != NULL)
	{
		while (i < sl->map_cnt)
			free(map[i++]);
		free(map);
	}
	free_cat(sl->mlx, sl->cat);
	mlx_terminate(sl->mlx);
	free(sl);
	exit(1);
}

void	unexpected_close(char *str, t_win *sl)
{
	if (sl->map != NULL)
		free_map(sl);
	if (sl->cat != NULL)
		free_cat(sl->mlx, sl->cat);
	if (sl->str_move != NULL)
		mlx_delete_image(sl->mlx, sl->str_move);
	ft_printf("%s\n", "Error");
	ft_printf("%s\n", str);
	free(sl);
	exit(2);
}
