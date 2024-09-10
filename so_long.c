/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/10 16:44:13 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define HEIGHT 1512
#define WIDTH 2688
#define BPP 4

void	sl_close(void *str)
{
		ft_printf("%s", (char *)str);
		exit(1);
}

void	move_persona(mlx_image_t *img, keys_t key)
{
	if (key == MLX_KEY_DOWN && img->instances[0].y <= HEIGHT - 64)
		img->instances[0].y += 64;
	if (key == MLX_KEY_UP && img->instances[0].y >= 64)
		img->instances[0].y -= 64;
	if (key == MLX_KEY_LEFT && img->instances[0].x >= 64)
		img->instances[0].x -= 64;
	if (key == MLX_KEY_RIGHT && img->instances[0].x >= WIDTH - 64)
		img->instances[0].x += 64;
}

void	sl_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		sl_close("Closing with ESC");
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_persona((mlx_image_t *)param, keydata.key);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_persona((mlx_image_t *)param, keydata.key);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_persona((mlx_image_t *)param, keydata.key);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_persona((mlx_image_t *)param, keydata.key);
}

int	main(void)
{
	mlx_t		*slx;
	mlx_image_t	*img;
	mlx_texture_t	*texture;

	slx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (slx == NULL)
		sl_close("Error");
	texture = mlx_load_png("textures/animals/ax_bear2.png");
	if (texture == NULL)
		sl_close("Error");
	img = mlx_texture_to_image(slx, texture);
	if(mlx_resize_image(img, 64, 64) == false)
		sl_close("Error");
	mlx_image_to_window(slx, img, 0, 0);
	mlx_close_hook(slx, sl_close, "Closing\n");	
	mlx_key_hook(slx, &sl_keyhook, "Closing with ESC\n");
	mlx_loop(slx);
	sl_close("");
	return (0);
}
