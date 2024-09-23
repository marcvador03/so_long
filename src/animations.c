/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/23 16:58:10 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/animations.h"

void	sl_close(void *str)
{
		ft_printf("%s", (char *)str);
		exit(1);
}

t_animation	*create_anime(double fps, int32_t x_move, int32_t y_move)
{
	t_animation	*anime;

	anime = (t_animation *)malloc(sizeof(t_animation));
	if (anime == NULL)
		sl_close("error malloc");
	anime->fps = fps;
	anime->x_move = x_move;
	anime->y_move = y_move;
	anime->count = 0;
	anime->frame = 0;
	anime->img = NULL;
	return (anime);
}	

void	anime_sprite(void *ptr)
{
	double	time[2];
	t_animation	*anime;
	int	i;

	anime = (t_animation *)ptr;
	i = anime->frame;
	ft_printf("%s %d", "test", anime->frame);
	time[0] = mlx_get_time();
	time[1] = time[0];
	while ((time[1] - anime->fps) <= time[0])
		time[1] = mlx_get_time();
	anime->img[i]->instances[0].enabled = true;
	if (i == 0)
		anime->img[anime->count - 1]->instances[0].enabled = false;
	else
		anime->img[i - 1]->instances[0].enabled = false;
	anime->frame = (anime->frame + 1) % anime->count;
}

void	load_sprite_img(t_mainwindow sl, t_sprite *sprite, t_animation *anime)
{
	size_t			i;
	mlx_image_t		**img;
	
	img = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * sprite->count);
	if (img == NULL)
		sl_close("erro malloc");
	i = 0;
	while (i < sprite->count)
	{
		img[i] = mlx_texture_to_image(sl.slx, sprite->texture[i]);
		mlx_image_to_window(sl.slx, img[i], 0, 80);
		img[i]->instances[0].enabled = false;
		i++;
	}
	anime->img = img;
	anime->count = sprite->count;
}
static mlx_texture_t	*create_sub_txt(size_t w, size_t h)
{
	mlx_texture_t	*texture;
	
	texture = (mlx_texture_t *)malloc(sizeof(mlx_texture_t));
	if (texture == NULL)
		sl_close("malloc texture");
	texture->width = w;	
	texture->height = h;	
	texture->bytes_per_pixel = BPP;
	texture->pixels = (uint8_t *)malloc(sizeof(uint8_t) * w * h * BPP);
	if (texture->pixels == NULL)
		sl_close("malloc texture");
	return (texture);	
}

t_sprite 	*create_sprite(mlx_texture_t *t, t_sprite in)
{
	t_sprite		*s;
	size_t			cnt[4];
	
	cnt[0] = in.pos_y;
	cnt[1] = 0;
	cnt[2] = in.pos_x;
	cnt[3] = 0;
	s = (t_sprite *)malloc(sizeof(t_sprite));
	s->texture = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * in.count);
	if (s->texture == NULL || s == NULL)
		sl_close("malloc texture");
	while(cnt[3] < in.count)
	{
		s->texture[cnt[3]] = create_sub_txt(in.width, in.height);
		while (cnt[0] <= in.height)
		{
			while (cnt[1] < in.width * BPP * cnt[0])
				s->texture[cnt[3]]->pixels[cnt[1]++] = t->pixels[cnt[2]++];
			cnt[0]++;
			cnt[2] = cnt[2] + ((t->width - in.width) * BPP);
		}
		cnt[3]++;
		cnt[1] = 0;
		cnt[2] = in.pos_x + in.width * BPP * cnt[3];
		cnt[0] = in.pos_y;
	}
	s->count = in.count;
	return (s);
}

mlx_texture_t 	*crop_texture(mlx_texture_t *t, t_sprite in)
{
	mlx_texture_t		*res;
	size_t				cnt[4];
	
	cnt[0] = in.pos_y;
	cnt[1] = 0;
	cnt[2] = in.pos_x;
	res = create_sub_txt(in.width, in.height);
	while (cnt[0] <= in.height)
	{
		while (cnt[1] < in.width * BPP * cnt[0])
			res->pixels[cnt[1]++] = t->pixels[cnt[2]++];
		cnt[0]++;
		cnt[2] = cnt[2] + ((t->width - in.width) * BPP);
	}
	return (res);
}

int		main(void)
{
	t_mainwindow	sl;
	mlx_texture_t	*texture;
	t_sprite		*sprite;
	mlx_image_t		*img;
	t_animation		*anime;
	
	sl.slx = mlx_init(64 * 15, 64 * 10, "Test Anim", true);
	if (sl.slx == NULL)
		sl_close("Error");
	texture = mlx_load_png(ATTACK01);	
	if (texture == NULL)
		sl_close("Error loading texture");
	sprite = create_sprite(texture, g_attack01); 
	img = mlx_texture_to_image(sl.slx, texture);
	mlx_image_to_window(sl.slx, img, 0, 0);
	anime = create_anime(1, 0, 0);
	load_sprite_img(sl, sprite, anime);
	mlx_loop_hook(sl.slx, anime_sprite, anime);
	mlx_loop(sl.slx);
}

