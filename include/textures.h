/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:58:32 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 01:57:03 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H
# include "so_long.h"

typedef struct s_sprite
{
	size_t			count;
	size_t			pos_x;
	size_t			pos_y;	
	size_t			width;
	size_t			height;
	size_t			dead_zone;
	size_t			r_width;
	size_t			r_height;
	mlx_texture_t	**texture;	
}	t_sprite;

# define PPT 64 
# define BCKG "textures/pixel_crawler_1.8/Environment/Green Woods/Assets/Tiles.png"

static const t_sprite	g_bckg = {1, 160, 0, 48, 48, 0, PPT, PPT, NULL};

# define WALL "textures/pixel_crawler_1.8/Environment/Green Woods/Assets/Props.png"

static const t_sprite	g_wall = {1, 80, 0, 32, 32, 0, PPT, PPT, NULL};

# define HERO "textures/pixel_crawler_1.8/Heroes/Knight/Idle/Idle-Sheet.png"

static const t_sprite	g_hero = {1, 0, 0, 32, 32, 0, PPT, PPT, NULL};

# define HERO_I "textures/pixel_crawler_1.8/Heroes/Knight/Idle/Idle-Sheet.png"

static const t_sprite	g_hero_idle = {4, 0, 0, 32, 32, 0, PPT, PPT, NULL};

# define CHEST_C "textures/pixel_crawler_1.8/Environment/Dungeon Prison/Assets/Props.png"

static const t_sprite	g_chest_c = {1, 95, 204, 32, 22, 0, PPT, 44, NULL};

# define CHEST_O "textures/pixel_crawler_1.8/Environment/Dungeon Prison/Assets/Props.png"

static const t_sprite	g_chest_o = {1, 127, 204, 32, 22, 0, PPT, 44, NULL};

# define MUSH "textures/pixel_crawler_1.8/Environment/Green Woods/Assets/Props.png"

static const t_sprite	g_mush = {1, 32, 16, 16, 16, 0, PPT / 2, PPT / 2, NULL};

# define EXIT "textures/pixel_crawler_1.8/Environment/Dungeon Prison/Assets/Tiles.png"

static const t_sprite	g_exit = {1, 32, 112, 32, 48, 0, PPT, PPT, NULL};

# define MONS "textures/pixel_crawler_1.8/Enemy/Orc Crew/Orc - Rogue/Idle/Idle-Sheet.png"

static const t_sprite	g_mons = {4, 0, 0, 32, 32, 0, PPT, PPT, NULL};

# define MONS_DEAD "textures/pixel_crawler_1.8/Enemy/Orc Crew/Orc - Rogue/Death/Death-Sheet.png"

static const t_sprite	g_mons_dead = {6, 15, 32, 32, 32, 35, 64, 64, NULL};

# define ARROW_UP "textures/pixel_crawler_1.8/Weapons/Wood/Wood.png"

static const t_sprite	g_arrow_up = {1, 16, 0, 12, 16, 0, 12, 16, NULL};

# define ARROW_R "textures/pixel_crawler_1.8/Weapons/Wood/Wood.png"

static const t_sprite	g_arrow_r = {1, 32, 0, 12, 16, 0, 12, 16, NULL};

#endif
