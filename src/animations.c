/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/25 10:30:52 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/animations.h"

t_anim	*create_anime(double fps, int32_t x_move, int32_t y_move)
{
	t_anim	*anime;

	anime = (t_anim *)malloc(sizeof(t_anim));
	if (anime == NULL)
		return (NULL);
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
	t_anim	*anime;
	int	i;

	anime = (t_anim *)ptr;
	i = anime->frame;
	time[0] = mlx_get_time();
	time[1] = time[0];
	while ((time[1] - anime->fps) <= time[0])
		time[1] = mlx_get_time();
	anime->img[i]->instances[0].enabled = true;
	if (i == 0 && anime->count > 1)
		anime->img[anime->count - 1]->instances[0].enabled = false;
	else if (anime->count > 1)
		anime->img[i - 1]->instances[0].enabled = false;
	anime->img[i]->instances[0].x += anime->x_move;
	anime->img[i]->instances[0].y += anime->y_move;
	anime->frame = (anime->frame + 1) % anime->count;
}


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
		return (NULL);
	init_w = t->width * BPP;
	cnt[0] = in.pos_y;
	cnt[1] = 0;
	cnt[2] = (init_w * cnt[0]) + (in.pos_x * BPP);
	cnt[3] = 0;
	s = (t_sprite *)malloc(sizeof(t_sprite));
	s->texture = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * in.count);
	if (s->texture == NULL || s == NULL)
		return (NULL);
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
	return (s);
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
	return (img);
}

/*int		main(void)
{
	t_mainwindow	sl;
	t_sprite		*sprite;
	//t_sprite		*sprite2;
	t_animation		*anime;

	sl.slx = mlx_init(64 * 15, 64 * 10, "Test Anim", true);
	if (sl.slx == NULL)
		sl_close("Error");
	//sprite = create_sprite(mlx_load_png(ATTACK01), g_attack01); 
	//anime = create_anime(1, 0, 0);
	sprite = create_sprite(mlx_load_png(KEY), g_key); 
	anime = create_anime(0.02, 0, 1);
	load_sprite_img(sl, sprite, anime);
	//texture_key = crop_texture(mlx_load_png(KEY), g_key); 
	mlx_loop_hook(sl.slx, anime_sprite, anime);
	mlx_loop(sl.slx);
}*/

