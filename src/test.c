/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:32:06 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/25 14:42:57 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"

int	main()
{
	mlx_t	*mlx;
	
	mlx = mlx_init(400, 400, "test MLX leaks", true);
	if (mlx == NULL)
		return (0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
	
