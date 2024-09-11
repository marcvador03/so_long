/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/11 23:51:18 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define HEIGHT 900
#define WIDTH 1440
#define BPP 4

void	sl_close(void *str)
{
		ft_printf("%s", (char *)str);
		exit(1);
}

void	move_persona(mlx_image_t *img, keys_t key)
{
	if (key == MLX_KEY_DOWN && img->instances->y <= (HEIGHT - 64))
	{
		img->instances->y +=64;
		ft_printf("down\n");
	}
		if (key == MLX_KEY_UP && img->instances->y >= 64)
	{
		img->instances->y -=64;
		ft_printf("up\n");
	}
		if (key == MLX_KEY_LEFT && img->instances->x >= 64)
	{
		img->instances->x -=64;
		ft_printf("left\n");
	}
		if (key == MLX_KEY_RIGHT && img->instances->x <= (WIDTH - 64))
	{
		img->instances->x +=64;
		ft_printf("right\n");
	}
}

void	sl_keyhook(mlx_key_data_t keydata, void *img)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		sl_close("Closing with ESC\n");
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_persona((mlx_image_t *)img, keydata.key);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_persona((mlx_image_t *)img, keydata.key);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_persona((mlx_image_t *)img, keydata.key);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_persona((mlx_image_t *)img, keydata.key);
}

int	main(int argc, char *argv[])
{
	t_mainwindow	sl;
	char			*line;

	if (argc != 2)
		sl_close("missing argument\n");
	sl.fd = open(argv[1], O_RDONLY);
	if (sl.fd == -1)
		sl_close("error while opening file\n");
	line = get_next_line(sl.fd);
	free(line);
	while (line != NULL)
		line = get_next_line(sl.fd);
	sl.slx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (sl.slx == NULL)
		sl_close("Error");
	sl.texture = mlx_load_png("textures/animals/ax_bear2.png");
	if (sl.texture == NULL)
		sl_close("Error");
	sl.img = mlx_texture_to_image(sl.slx, sl.texture);
	if(mlx_resize_image(sl.img, 64, 64) == false)
		sl_close("Error");
	mlx_image_to_window(sl.slx, sl.img, 0, 0);
	mlx_close_hook(sl.slx, sl_close, "Closing\n");	
	mlx_key_hook(sl.slx, &sl_keyhook, sl.img);
	mlx_loop(sl.slx);
	sl_close("");
	return (0);
}
