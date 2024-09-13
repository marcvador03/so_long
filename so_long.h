/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/14 01:58:47 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/getnextline/get_next_line.h"

typedef struct	s_map
{
	char	c;
	size_t	instance;
} t_map;
typedef struct	s_mainwindow 
{
	int				fd;
	t_map			**map;
	mlx_t			*slx;
	mlx_image_t		*hero;
	mlx_image_t		*wall;
	mlx_image_t		*item;
	mlx_image_t		*exit;
	mlx_image_t		*bckg;
	unsigned int	h_map;
	unsigned int	w_map;
	unsigned int	item_cnt;
	unsigned int	move_cnt;	
} t_mainwindow;

int	create_rgba(int r, int g, int b, int a);
int	get_r(int rgba);
int	get_g(int rgba);
int get_b(int rgba);
int	get_a(int rgba);
int	add_shade(int color, double d);
int	get_neg_color(int color);
#endif

