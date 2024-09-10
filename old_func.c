/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:46:50 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/10 15:46:53 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sl_square(mlx_image_t *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
			mlx_put_pixel(img, i++, j, color);
		color = add_shade(color, 0.00005);
		j++;
	}
}
