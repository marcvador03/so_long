/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/20 23:19:14 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/animations.h"

void	sl_close(void *str)
{
		ft_printf("%s", (char *)str);
		exit(1);
}

int		main(void)
{
	t_mainwindow	sl;
	int32_t	width;
	int32_t	height;
	mlx_texture_t	*texture;
	mlx_texture_t	*texture2;
	mlx_image_t		*img;
	mlx_image_t		*img2;
	size_t	i;
	size_t	j;
	size_t	x;
	
	sl.slx = mlx_init(64 * 15, 64 * 10, "Test Anim", true);
	if (sl.slx == NULL)
		sl_close("Error");
	mlx_get_monitor_size(0, &width, &height);
	texture = mlx_load_png("textures/fantasy/Character/Attack-01/Attack-01-Sheet.png");	
	if (texture == NULL)
		sl_close("Error loading texture");
	texture2 = (mlx_texture_t *)malloc(sizeof(mlx_texture_t));
	if (texture2 == NULL)
		exit(1);
	texture2->width = 96;	
	texture2->height = 80;	
	texture2->bytes_per_pixel = 4;
	texture2->pixels = (uint8_t *)malloc(sizeof(uint8_t) * 96 * 80 * 4);
	i = 0;
	j = 1;
	x = i;
	while (j <= 80)
	{
		while (x < 96 *	4 * j)
		{
			texture2->pixels[x] = texture->pixels[i];
			i++;
			x++;
		}
		j++;
		i = i + ((768 - 96) * 4);
	}
	img = mlx_texture_to_image(sl.slx, texture);
	img2 = mlx_texture_to_image(sl.slx, texture2);
	mlx_image_to_window(sl.slx, img, 0, 0);
	mlx_image_to_window(sl.slx, img2, 0, 80);
	mlx_loop(sl.slx);
}

