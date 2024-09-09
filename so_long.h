/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/08 17:02:29 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int get_g(int trgb);
int	get_b(int trgb);
void	sl_exit(mlx_t *slx);
#endif

