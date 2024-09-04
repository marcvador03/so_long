/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/04 17:37:04 by mfleury          ###   ########.fr       */
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
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct	s_data {
		void	*img;
		char	*addr;
		int	bits_per_pixel;
		int	line_length;
		int	endian;
}	t_data;


void	sl_exit();
#endif

