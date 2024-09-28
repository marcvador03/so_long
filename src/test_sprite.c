/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:28:09 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/28 23:44:00 by mfleury          ###   ########.fr       */
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

mlx_texture_t	*create_mirror(mlx_texture_t *in)
{
	mlx_texture_t	*out;
	uint32_t		max;
	uint32_t		q;
	uint32_t		i;

	max = in->width * BPP + in->height * BPP;
	q = 0;
	i = 0;
	out = create_sub_txt(in->width, in->height);
	if (out == NULL)
		return (NULL);
	while (i < max)
	{
		out->pixels[(i * BPP) + q] = in->pixels[(max - (i * BPP)) - (q ^ 3)];
		q = (q + 1) % 4;
		if (q == 0)
			i++;
	}
	return (out);
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

void	set_var(size_t cnt[4], size_t init[2], t_sprite in, int i)
{
	/*cnt[0] = in.pos_y;
	cnt[1] = 0;
	cnt[2] = (init[W] * cnt[0]) + (in.pos_x * BPP);
	cnt[3] = 0;*/
	cnt[1] = in.pos_y;
	if (i == 0)
		cnt[2] = (init[W] * cnt[1]) + (in.pos_x * BPP);
	else
		cnt[2] = BPP * (in.pos_x + (init[W] * cnt[1]) + in.width);
	cnt[3] = 0;
}

int	init_var(size_t **cnt, size_t **init, t_sprite **s, t_sprite in)
{
	*cnt = (size_t *)calloc(4, sizeof(size_t));
	*init = (size_t *)calloc(2, sizeof(size_t));
	*s = (t_sprite *)malloc(sizeof(t_sprite));
	(*s)->texture = malloc(sizeof(mlx_texture_t *) * in.count);
	if ((*s)->texture == NULL || *s == NULL || *cnt == NULL || *init == NULL)
		return (0);
	return (1);
}

void	free_sprite(size_t *cnt, size_t *init, t_sprite *s, mlx_texture_t *t)
{
	free(cnt);
	free(init);
	free(s);
	mlx_delete_texture(t);
}

mlx_texture_t	*sprite_loop(mlx_texture_t *t_in, t_sprite in, size_t cnt[4], size_t init[2])
{
	mlx_texture_t	*t;

	t = create_sub_txt(in.width, in.height);
	if (t == NULL)
		return (NULL);
	while (cnt[1] < (in.pos_y + in.height))
	{
		while (cnt[2] < (init[W] * cnt[1]) + (in.pos_x + in.width) * BPP)
			t->pixels[cnt[3]++] = t_in->pixels[cnt[2]++];
		cnt[1]++;
		cnt[2] = cnt[2] - (in.width * BPP) + init[W];
	}
	return (t);
}

t_sprite	*create_sprite(mlx_texture_t *t, t_sprite in)
{
	t_sprite	*s;
	size_t		*cnt;
	size_t		*init;

	cnt = NULL;
	init = NULL;
	s = NULL;
	if (in.count <= 0 || t == NULL)
		return (mlx_delete_texture(t), NULL);
	if (init_var(&cnt, &init, &s, in) == 0)
		return (free_sprite(cnt, init, s, t), NULL);
	init[W] = t->width * BPP;
	init[H] = t->height * BPP;
	set_var(cnt, init, in, 0);
	while (cnt[0] < in.count)
	{
		s->texture[cnt[0]] = sprite_loop(t, in, cnt, init);
		if (s->texture[cnt[0]] == NULL)
			return (NULL);
		cnt[0]++;
	}
	set_var(cnt, init, in, 1); //check
	sprite_init(s, in);
	return (free_sprite(cnt, init, NULL, t), s);
}

/*int	main()
{
	uint8_t	*pixel;
	int		i;

	pixel = (uint8_t *)calloc(5, sizeof(uint8_t));
	pixel[0] = 'a';	
	pixel[1] = 'b';	
	pixel[2] = 'c';	
	pixel[3] = 'd';	
	pixel[4] = 'e';	
	i = 0;
	while (i < 5)
		ft_printf("%c\n", pixel[i++]);
	*pixel = *pixel << 8;
	i = 0;
	while (i < 5)
		ft_printf("%c\n", pixel[i++]);
}*/

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
