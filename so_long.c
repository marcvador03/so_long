/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/09 20:51:39 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define HEIGHT 720
#define WIDTH 480
#define BPP 4

void	sl_exit(mlx_t *slx)
{
	mlx_terminate(slx);
	exit(1);
}	

int	main(void)
{
	mlx_t		*slx;
	mlx_image_t	*img;
	mlx_texture_t	*texture;

	slx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (slx == NULL)
		sl_exit(NULL);
	img = mlx_new_image(slx, WIDTH, HEIGHT);
	if (img == NULL)
		exit(1);
	texture = mlx_load_png("textures/fruits/01.png");
	if (texture == NULL)
		sl_exit(NULL);
	img = mlx_texture_to_image(slx, texture);
	//ft_memset(img->pixels, 0xFF, img->width * img->height * 4);  
	mlx_image_to_window(slx, img, 300, 0);	
	mlx_loop(slx);

	sl_exit(slx);
	return (0);
}
