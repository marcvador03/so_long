/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:58:32 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/26 12:32:17 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "animations.h"
//# define HERO "textures/knight/Walk1.png"
# define ITEM "textures/graveyard/png/Objects/Skeleton.png"
//# define WALL "textures/graveyard/png/Objects/TombStone1.png"
//# define BCKG "textures/graveyard/png/Tiles/Tile9.png"
# define EXIT "textures/graveyard/png/Objects/ArrowSign.png"

# define PPT 64 
# define BCKG "textures/pixel_crawler_1.8/Environment/Green Woods/Assets/Tiles.png"
static const t_sprite g_bckg = { 1, 160, 0, 48, 48, PPT, PPT, NULL };
# define WALL "textures/pixel_crawler_1.8/Environment/Green Woods/Assets/Props.png"
static const t_sprite g_wall = { 1, 80, 0, 32, 32, PPT, PPT, NULL };
# define HERO_IDLE "textures/pixel_crawler_1.8/Heroes/Knight/Idle/Idle-Sheet.png"
static const t_sprite g_hero_idle = { 4, 0, 0, 32, 32, PPT, PPT, NULL };
# define HERO_RUN "textures/pixel_crawler_1.8/Heroes/Knight/Run/Run2-Sheet.png"
static const t_sprite g_hero_run = { 6, 0, 0, 32, 32, PPT, PPT, NULL };
# define HERO_DEAD "textures/pixel_crawler_1.8/Heroes/Knight/Death/Death-Sheet.png"
static const t_sprite g_hero_dead = { 6, 0, 0, 32, 48, PPT, PPT, NULL };
# define CHEST "textures/pixel_crawler_1.8/Environment/Dungeon Prison/Assets/Props.png"
static const t_sprite g_chest = { 1, 96, 203, 32, 22, PPT, PPT, NULL };
# define KEY "textures/fantasy/Assets/Tiles.png"
static const t_sprite g_key = { 1, 240, 322, 15, 10, 15, 10, NULL };

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
