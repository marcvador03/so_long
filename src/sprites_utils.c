/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:29:04 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 21:00:54 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sprite_init(t_sprite *s, t_sprite in)
{
	s->count = in.count;
	s->pos_x = 0;
	s->pos_y = 0;
	s->width = in.width;
	s->height = in.height;
	s->r_width = in.r_width;
	s->r_height = in.r_height;
}

int	init_var(size_t **cnt, t_sprite **s, t_sprite in)
{
	*cnt = (size_t *)ft_calloc(5, sizeof(size_t));
	*s = (t_sprite *)ft_calloc(sizeof(t_sprite), 1);
	(*s)->texture = ft_calloc(in.count, sizeof(mlx_texture_t *));
	if ((*s)->texture == NULL || *s == NULL || *cnt == NULL)
		return (0);
	return (1);
}

void	set_q(size_t cnt[5], int32_t *q)
{
	*q = (*q + 1) % BPP;
	if (*q == 0)
	{
		cnt[PX] += BPP;
		cnt[W] += BPP;
	}
}

void	set_var(size_t cnt[5], int32_t *q, t_sprite in, int32_t w)
{
	*q = 0;
	cnt[INIT] = (in.pos_x + (in.pos_y * w)) * BPP;
	cnt[INIT] += cnt[H] * w * BPP;
	cnt[W] = 0;
	cnt[H]++;
}

void	set_var_m(size_t cnt[5], int32_t *q, t_sprite in, int32_t w)
{
	*q = 0;
	cnt[INIT] = ((in.pos_x + (in.pos_y * w)) + in.width) * BPP - 4;
	cnt[INIT] += cnt[H] * w * BPP;
	cnt[W] = 0;
	cnt[H]++;
}
