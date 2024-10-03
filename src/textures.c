/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:33:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 00:45:38 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_txt(t_win *sl, size_t *cnt, mlx_texture_t *t_in, mlx_texture_t *t)
{
	free(cnt);
	mlx_delete_texture(t);
	mlx_delete_texture(t_in);
	unexpected_close(ERR_LOAD_TEXTURE, sl);
}

mlx_texture_t	*create_sub_txt(size_t w, size_t h)
{
	mlx_texture_t	*texture;

	if (w == 0 && h == 0)
		return (NULL);
	texture = (mlx_texture_t *)malloc(sizeof(mlx_texture_t));
	if (texture == NULL)
		return (NULL);
	texture->width = w;
	texture->height = h;
	texture->bytes_per_pixel = BPP;
	texture->pixels = (uint8_t *)malloc(sizeof(uint8_t) * w * h * BPP);
	if (texture->pixels == NULL)
		return (NULL);
	return (texture);
}

mlx_image_t	*load_txt_m(t_win *sl, mlx_texture_t *t_in, t_sprite in)
{
	mlx_texture_t	*t;
	mlx_image_t		*img;
	int32_t			q;
	size_t			*cnt;

	cnt = (size_t *)ft_calloc(5, sizeof(size_t));
	t = create_sub_txt(in.width, in.height);
	if (cnt == NULL || t_in == NULL || t == NULL)
		free_txt(sl, cnt, t_in, t);
	set_var_m(cnt, &q, in, t_in->width);
	while (cnt[H] <= in.height)
	{
		while (cnt[W] < (in.width * BPP))
		{
			t->pixels[cnt[PX] + q] = t_in->pixels[cnt[INIT] - cnt[W] + q];
			set_q(cnt, &q);
		}
		set_var_m(cnt, &q, in, t_in->width);
	}
	img = mlx_texture_to_image(sl->mlx, t);
	if (img == NULL || mlx_resize_image(img, in.r_width, in.r_height) == false)
		free_txt(sl, cnt, t_in, t);
	return (mlx_delete_texture(t_in), mlx_delete_texture(t), img);
}

mlx_image_t	*load_txt(t_win *sl, mlx_texture_t *t_in, t_sprite in)
{
	mlx_texture_t	*t;
	mlx_image_t		*img;
	int32_t			q;
	size_t			*cnt;

	cnt = (size_t *)ft_calloc(5, sizeof(size_t));
	t = create_sub_txt(in.width, in.height);
	if (cnt == NULL || t_in == NULL || t == NULL)
		free_txt(sl, cnt, t_in, t);
	set_var(cnt, &q, in, t_in->width);
	while (cnt[H] <= in.height)
	{
		while (cnt[W] < (in.width * BPP))
		{
			t->pixels[cnt[PX] + q] = t_in->pixels[cnt[INIT] + cnt[W] + q];
			set_q(cnt, &q);
		}
		set_var(cnt, &q, in, t_in->width);
	}
	img = mlx_texture_to_image(sl->mlx, t);
	if (img == NULL || mlx_resize_image(img, in.r_width, in.r_height) == false)
		free_txt(sl, cnt, t_in, t);
	return (free(cnt), mlx_delete_texture(t_in), mlx_delete_texture(t), img);
}
