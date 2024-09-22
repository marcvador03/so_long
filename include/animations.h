/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:32 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/21 15:42:46 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_H
# define ANIMATIONS_H
# include "so_long.h"
typedef struct	s_sprite
{
	size_t			sprite_count;
	mlx_texture_t	*texture;	
}	t_sprite;
#endif
