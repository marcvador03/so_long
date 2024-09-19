/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:27 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/19 17:56:10 by mfleury          ###   ########.fr       */
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
	
	mlx_get_monitor_size(0, &width, &height);
	sl.slx = mlx_init(64 * 15, 64 * 10, "Test Anim", true);
	if (sl.slx == NULL)
		sl_close("Error");
	
	mlx_loop(sl.slx);
}

