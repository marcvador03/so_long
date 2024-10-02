/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:58:32 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/02 10:53:27 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "so_long.h"

typedef struct	s_sprite
{
//	char			*path;
	size_t			count;
	size_t			pos_x;
	size_t			pos_y;	
	size_t			width;
	size_t			height;
	size_t			r_width;
	size_t			r_height;
	mlx_texture_t	**texture;	
}	t_sprite;

# define PPT 64 
# define BCKG "textures/pixel_crawler_1.8/Environment/Green Woods/Assets/Tiles.png"
static const t_sprite g_bckg = { 1, 160, 0, 48, 48, PPT, PPT, NULL };
# define WALL "textures/pixel_crawler_1.8/Environment/Green Woods/Assets/Props.png"
static const t_sprite g_wall = { 1, 80, 0, 32, 32, PPT, PPT, NULL };
# define HERO "textures/pixel_crawler_1.8/Heroes/Knight/Idle/Idle-Sheet.png"
static const t_sprite g_hero = { 1, 0, 0, 32, 32, PPT, PPT, NULL };
# define HERO_IDLE "textures/pixel_crawler_1.8/Heroes/Knight/Idle/Idle-Sheet.png"
static const t_sprite g_hero_idle = { 4, 0, 0, 32, 32, PPT, PPT, NULL };
# define HERO_RUN "textures/pixel_crawler_1.8/Heroes/Knight/Run/Run2-Sheet.png"
static const t_sprite g_hero_run = { 6, 0, 0, 32, 32, PPT, PPT, NULL };
# define HERO_DEAD "textures/pixel_crawler_1.8/Heroes/Knight/Death/Death-Sheet.png"
static const t_sprite g_hero_dead = { 6, 0, 0, 48, 32, 96, PPT, NULL };
# define CHEST_C "textures/pixel_crawler_1.8/Environment/Dungeon Prison/Assets/Props.png"
static const t_sprite g_chest_c = { 1, 95, 204, 32, 22, PPT, 44, NULL };
# define CHEST_O "textures/pixel_crawler_1.8/Environment/Dungeon Prison/Assets/Props.png"
static const t_sprite g_chest_o = { 1, 127, 204, 32, 22, PPT, 44, NULL };
# define MUSH "textures/pixel_crawler_1.8/Environment/Green Woods/Assets/Props.png"
static const t_sprite g_mush = { 1, 32, 16, 16, 16, PPT / 2, PPT / 2, NULL };
# define EXIT "textures/pixel_crawler_1.8/Environment/Dungeon Prison/Assets/Tiles.png"
static const t_sprite g_exit = { 1, 32, 112, 32, 48, PPT, PPT, NULL };
# define MONS "textures/pixel_crawler_1.8/Enemy/Orc Crew/Orc - Rogue/Idle/Idle-Sheet.png"
static const t_sprite g_mons = { 4, 64, 0, 32, 32, PPT, PPT, NULL };
# define MONS_DEAD "textures/pixel_crawler_1.8/Enemy/Orc Crew/Orc - Rogue/Death/Death-Sheet.png"
static const t_sprite g_mons_dead = { 6, 0, 0, 48, 32, 96, PPT, NULL };

//# define HERO "textures/pixel_crawler_1.8/Heroes/Knight/Idle/Idle-Sheet.png"
//static const t_sprite g_hero = { 1, 0, 0, 32, 32, PPT, PPT, NULL };
/*# define ATTACK01 "textures/fantasy/Character/Attack-01/Attack-01-Sheet.png"
static const t_sprite g_attack01 = { 8, 0, 0, 96, 80, NULL };
# define HERO_IDLE "textures/fantasy/Character/Idle/Idle-Sheet.png"
static const t_sprite g_hero_idle = { 4, 0, 0, 64, 80, NULL };
# define RUN "textures/fantasy/Character/Run/Run-Sheet.png"
static const t_sprite g_run = { 8, 0, 0, 80, 80, NULL };
# define KEY "textures/fantasy/Assets/Tiles.png"
static const t_sprite g_key = { 1, 240, 322, 15, 10, NULL };
# define WALL "textures/fantasy/Assets/Tiles.png"
static const t_sprite g_wall = { 1, 95, 160, 48, 48, NULL };
# define WALL2 "textures/fantasy/Assets/Tiles.png"
static const t_sprite g_wall2 = { 1, 160, 224, 16, 48, NULL };
# define CHEST "textures/fantasy/Assets/Tiles.png"
static const t_sprite g_chest = { 2, 288, 275, 32, 29, NULL };
# define BCKG "textures/fantasy/Assets/Tiles.png"
static const t_sprite g_BCKG = { 1, 289, 275, 30, 29, NULL };
*/



#endif
