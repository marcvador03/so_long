/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:30:42 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 01:57:03 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "so_long.h"

typedef struct s_anim
{
	char			*name;
	double			fps;
	double			time;
	size_t			count;
	int32_t			**frame;
	int32_t			depth;
	mlx_image_t		**img;
}	t_anim;

typedef struct s_img_cat
{
	t_sprite	*s_wall;
	t_sprite	*s_item_c;
	t_sprite	*s_exit;
	t_sprite	*s_bckg;
	t_sprite	*s_hero_idle;
	t_sprite	*sm_hero_idle;
	t_sprite	*s_item_o;
	t_sprite	*s_mush;
	t_sprite	*s_mons;
	t_sprite	*s_mons_dead;
	t_sprite	*s_arrow_up;
	t_sprite	*s_arrow_down;
	t_sprite	*s_arrow_r;
	t_sprite	*s_arrow_l;
	t_anim		*wall;
	t_anim		*item_c;
	t_anim		*exit;
	t_anim		*bckg;
	t_anim		*hero_idle;
	t_anim		*hero_idle_m;
	t_anim		*hero_dead;
	t_anim		*hero_dead_m;
	t_anim		*item_o;
	t_anim		*mush;
	t_anim		*mons;
	t_anim		*mons_dead;
	t_anim		*arrow_up;
	t_anim		*arrow_down;
	t_anim		*arrow_r;
	t_anim		*arrow_l;
}	t_cat;

#endif
