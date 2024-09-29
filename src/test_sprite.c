/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:28:09 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/29 19:35:14 by mfleury          ###   ########.fr       */
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

void	sprite_init(t_sprite *s, t_sprite in)
{
	s->count = in.count;
	s->pos_x = 0;
	s->pos_y = 0;
	s->width = in.width;
	s->height = in.height;
	s->r_width = in.r_width;
	s->r_height = in.r_height;
}

int	init_var(size_t **cnt, t_sprite **s, t_sprite in)
{
	*cnt = (size_t *)calloc(5, sizeof(size_t));
	*s = (t_sprite *)malloc(sizeof(t_sprite));
	(*s)->texture = malloc(sizeof(mlx_texture_t *) * in.count);
	if ((*s)->texture == NULL || *s == NULL || *cnt == NULL)
		return (0);
	return (1);
}

void	free_sprite(size_t *cnt, t_sprite *s, mlx_texture_t *t)
{
	free(cnt);
	free(s);
	mlx_delete_texture(t);
}

mlx_texture_t	*sprite_loop_m(mlx_texture_t *t_in, t_sprite in, size_t cnt[5])
{
	mlx_texture_t	*t;
	int32_t			q;
	uint32_t		i;

	t = create_sub_txt(in.width, in.height);
	if (t == NULL)
		return (NULL);
	q = 0;
	i = 0;
	cnt[INIT] = (in.pos_x + in.width + (in.pos_y * in.width)) * BPP;
	cnt[H] = 1;
	cnt[W] = cnt[H] * t_in->width * BPP; 
	while (cnt[H] < in.height)
	{
		while (i < in.width)
		{
			t->pixels[cnt[PIX] + q] = t_in->pixels[cnt[INIT] - cnt[W] - q ^ 3];
			q = (q + 1) % BPP;
			if (q == 0)
			{
				cnt[PIX] += BPP;
				cnt[W] += BPP;
				i++;
			}
		}
		cnt[H]++;
		cnt[W] = cnt[H] * t_in->width * BPP; 
		i = 0;
	}
	return (t);
}

mlx_texture_t	*sprite_loop(mlx_texture_t *t_in, t_sprite in, size_t cnt[5])
{
	mlx_texture_t	*t;
	int32_t			q;
	uint32_t		i;

	t = create_sub_txt(in.width, in.height);
	if (t == NULL)
		return (NULL);
	q = 0;
	i = 0;
	cnt[INIT] = (in.pos_x + (in.pos_y * in.width)) * BPP;
	cnt[H] = 1;
	cnt[W] = cnt[H] * t_in->width * BPP; 
	while (cnt[H] < in.height)
	{
		while (i < in.width)
		{
			t->pixels[cnt[PIX] + q] = t_in->pixels[cnt[INIT] + cnt[W] + q];
			q = (q + 1) % BPP;
			if (q == 0)
			{
				cnt[PIX] += BPP;
				cnt[W] += BPP;
				i++;
			}
		}
		cnt[H]++;
		cnt[W] = cnt[H] * t_in->width * BPP; 
		i = 0;
	}
	return (t);
}

t_sprite	*create_sprite(mlx_texture_t *t, t_sprite in)
{
	t_sprite	*s;
	size_t		*cnt;

	cnt = NULL;
	s = NULL;
	if (in.count <= 0 || t == NULL)
		return (mlx_delete_texture(t), NULL);
	if (init_var(&cnt, &s, in) == 0)
		return (free_sprite(cnt, s, t), NULL);
	while (cnt[TXT] < in.count)
	{
		s->texture[cnt[TXT]] = sprite_loop(t, in, cnt);
		if (s->texture[cnt[TXT]] == NULL)
			return (NULL);
		cnt[TXT]++;
		cnt[PIX] = 0;
		cnt[INIT] += in.width * BPP; 
	}
	sprite_init(s, in);
	return (free_sprite(cnt, NULL, t), s);
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
	if (mlx_resize_image(img, in.r_width, in.r_height) == false)
		return (NULL);
	return (mlx_delete_texture(t), mlx_delete_texture(t_out), img);
}
