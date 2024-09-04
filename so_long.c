/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/04 17:08:20 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit()
{
	exit(1);
}	

void	sl_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

void	sl_triangle(t_data *data, int x, int y, int color_init)
{
	int	i;
	int	color;

	i = 0;
	color = color_init;
	while (i <= 400)
	{
		sl_mlx_pixel_put(data, x + i, y - i, color);
		i++;
	}
	x = x + i - 1;
	y = y - i + 1;
	i = 0;
	while (i <= 400)
	{
		sl_mlx_pixel_put(data, x + i, y + i, color);
		i++;
	}
	x = x + i - 1;
	y = y + i - 1;
	i = 0;
	while (i <= 800)
	{
		sl_mlx_pixel_put(data, x - i, y, color);
		i++;
	}
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	x;
	int	y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	if (mlx_win == NULL)
		exit(1);
	img.img = mlx_new_image(mlx, 1920, 1080);
	if (img.img == NULL)
		exit(1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);  
	x = 100;
	y = 1000;
	sl_triangle(&img, x, y, 0x0000FF00); 
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	/*sl_exit();
	return (0);*/
}
