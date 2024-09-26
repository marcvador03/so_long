/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:05:14 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/26 15:06:48 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static mlx_texture_t	*create_sub_txt(size_t w, size_t h)
{
	mlx_texture_t	*texture;
	
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

t_sprite 	*create_sprite(mlx_texture_t *t, t_sprite in)
{
	t_sprite		*s;
	size_t			cnt[4];
	size_t			init_w;
	
	if (in.count <= 0 || t == NULL)
		return (mlx_delete_texture(t), NULL);
	init_w = t->width * BPP;
	cnt[0] = in.pos_y;
	cnt[1] = 0;
	cnt[2] = (init_w * cnt[0]) + (in.pos_x * BPP);
	cnt[3] = 0;
	s = (t_sprite *)malloc(sizeof(t_sprite));
	s->texture = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * in.count);
	if (s->texture == NULL || s == NULL)
		return (mlx_delete_texture(t), NULL);
	while(cnt[3] < in.count)
	{
		s->texture[cnt[3]] = create_sub_txt(in.width, in.height);
		if (s->texture[cnt[3]] == NULL)
			return (NULL);
		while (cnt[0] < (in.pos_y + in.height))
		{
			while (cnt[2] < (init_w * cnt[0]) + (in.pos_x + in.width) * BPP)
				s->texture[cnt[3]]->pixels[cnt[1]++] = t->pixels[cnt[2]++];
			cnt[0]++;
			cnt[2] = cnt[2] - (in.width * BPP) + init_w;
		}
		cnt[1] = 0;
		cnt[3]++;
		cnt[0] = in.pos_y;
		in.pos_x += (init_w * cnt[0]) + in.width;
		cnt[2] = in.pos_x * BPP;
	}
	s->count = in.count;
	s->pos_x = 0;
	s->pos_y = 0;
	s->width = in.width;
	s->height = in.height;
	s->r_width = in.r_width;
	s->r_height = in.r_height;
	return (mlx_delete_texture(t), s);
}

mlx_image_t	*load_texture(mlx_t sl, mlx_texture_t *t, t_sprite in)
{
	mlx_texture_t		*t_out;
	mlx_image_t			*img;
	size_t				cnt[3];
	size_t				init_w;
	
	if (t == NULL)
		return (NULL);
	init_w = t->width * BPP;
	cnt[0] = in.pos_y;
	cnt[1] = 0;
	cnt[2] = (init_w * cnt[0]) + (in.pos_x * BPP);
	t_out = create_sub_txt(in.width, in.height);
	if (t_out == NULL)
		return (NULL);
	while (cnt[0] < (in.pos_y + in.height))
	{
		while (cnt[2] < (init_w * cnt[0]) + (in.pos_x + in.width) * BPP)
			t_out->pixels[cnt[1]++] = t->pixels[cnt[2]++];
		cnt[0]++;
		cnt[2] = cnt[2] - (in.width * BPP) + init_w;
	}
	img = mlx_texture_to_image(&sl, t_out);
	if(mlx_resize_image(img, in.r_width, in.r_height) == false)
		return (NULL);
	mlx_delete_texture(t);
	mlx_delete_texture(t_out);
	return (img);
}
