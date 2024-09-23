/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:32 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/23 16:41:10 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_H
# define ANIMATIONS_H
# include "so_long.h"
typedef struct	s_sprite
{
//	char			*path;
	size_t			count;
	size_t			pos_x;
	size_t			pos_y;	
	size_t			width;
	size_t			height;
	mlx_texture_t	**texture;	
}	t_sprite;
typedef struct	s_animation
{
	double			fps;
	int32_t			x_move;
	int32_t			y_move;
	size_t			count;
	int				frame;
	mlx_image_t		**img;
}	t_animation;
#endif
