/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:17:46 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/01 21:45:40 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collect_item(t_win *sl, t_map **map, t_map a)
{
	switch_img(&map[a.y][a.x], sl->cat->item_o, sl->cat->item_c);
	activate_anim(&map[a.y][a.x], sl->cat->mush, sl->cat->item_o);
	//map[a.y][a.x].cur_a->img[0]->instances[map[a.y][a.x].inst].enabled= false;
	map[a.y][a.x].c = '0';
	sl->item_cnt--;
}
