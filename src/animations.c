/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/23 12:00:05 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/animations.h"

void	sl_close(void *str)
{
		ft_printf("%s", (char *)str);
		exit(1);
}
static mlx_texture_t	*create_sub_txt(size_t w, size_t h)
{
	mlx_texture_t	*texture;
	
	texture = (mlx_texture_t *)malloc(sizeof(mlx_texture_t));
	if (texture == NULL)
		sl_close("malloc texture");
	texture->width = 96;	
	texture->height = 80;	
	texture->bytes_per_pixel = 4;
	texture->pixels = (uint8_t *)malloc(sizeof(uint8_t) * w * h * BPP);
	if (texture->pixels == NULL)
		sl_close("malloc texture");
	return (texture);	
}

t_sprite 	*create_sprite(mlx_texture_t *t, size_t w, size_t h, size_t n)
{
	t_sprite		*s;
	size_t			cnt[4];
	
	cnt[0] = 1;
	cnt[1] = 0;
	cnt[2] = 0;
	cnt[3] = 0;
	s = (t_sprite *)malloc(sizeof(t_sprite));
	s->texture = (mlx_texture_t **)malloc(sizeof(mlx_texture_t) * n);
	if (s->texture == NULL || s == NULL)
		sl_close("malloc texture");
	while(cnt[3] < n)
	{
		s->texture[cnt[3]] = create_sub_txt(w, h);
		while (cnt[0] <= h)
		{
			while (cnt[1] < w * BPP * cnt[0])
				s->texture[cnt[3]]->pixels[cnt[1]++] = t->pixels[cnt[2]++];
			cnt[0]++;
			cnt[2] = cnt[2] + ((t->width - w) * BPP);
		}
		cnt[3]++;
		cnt[1] = 0;
		cnt[2] = w * BPP * cnt[3];
		cnt[0] = 1;
	}
	s->sprite_count = n;
	return (s);
}
int		main(void)
{
	t_mainwindow	sl;
	int32_t	width;
	int32_t	height;
	mlx_texture_t	*texture;
	t_sprite		*sprite;
	mlx_image_t		*img[9];
	int				i;
	
	sl.slx = mlx_init(64 * 15, 64 * 10, "Test Anim", true);
	if (sl.slx == NULL)
		sl_close("Error");
	mlx_get_monitor_size(0, &width, &height);
	texture = mlx_load_png(ATTACK01);	
	if (texture == NULL)
		sl_close("Error loading texture");
	sprite = create_sprite(texture, 96, 80, 8); 
	img[0] = mlx_texture_to_image(sl.slx, texture);
	mlx_image_to_window(sl.slx, img[0], 0, 0);
	i = 0;
	while (i < 8)
	{
		img[i] = mlx_texture_to_image(sl.slx, sprite->texture[i]);
		mlx_image_to_window(sl.slx, img[i], i * 96, 80);
		i++;
	}
	mlx_loop(sl.slx);
}

