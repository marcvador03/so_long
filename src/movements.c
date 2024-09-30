/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:17:46 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 18:49:37 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*void	update_map(t_win *sl, t_map map, int32_t move[2], int32_t pos[2])
{
	
	if (pos[X] / PPT != sl->w_hero || pos[Y] / PPT != sl->h_hero)
	{
		sl->w_hero = pos[X] / PPT;
		sl->h_hero = pos[Y] / PPT;
	}
}*/
/*t_map	*find_map_adj(t_map map, int32_t move[2], int32_t hero[4])
{
	t_map	next_map;

	next_map = 0;
	if (move[Y] < 0)
		next_map = map_adj[(hero[Y] / PPT) - 1][hero[X] / PPT];
	else if (move[X] < 0)
		next_map = map_adj[(hero[Y] / PPT)][(hero[X] / PPT) - 1];
	else if (move[X] > 0)
		next_map = map_adj[(hero[Y] / PPT)][(hero[X] / PPT) + 1];
	else if (move[Y] > 0)
		next_map = map_adj[(hero[Y] / PPT) + 1][hero[X] / PPT];
}*/
void	collect_item(t_win *sl, t_map **map, t_map a)
{
	//place for animation
	map[a.y][a.x].img[0]->instances[map[a.y][a.x].instance].enabled= false;
	map[a.y][a.x].c = '0';
	sl->item_cnt--;
}

size_t	move_hero(t_map **map_adj, int32_t move[2], int32_t hero[4])
{
	//update image?
	int32_t		i;

	i = 0;
	while (map_adj[i] != NULL)
	{
		if (map_adj[i]->c == 'C')
			collect_item(*map_adj[i]);
		else if (map_adj[i]-> == 'E')	
		i++;
	}
	map.img[0]->instances[map.instance].x += move[X]; //manage img frames		
	map.img[0]->instances[map.instance].y += move[Y]; //manage img frames
		
}

