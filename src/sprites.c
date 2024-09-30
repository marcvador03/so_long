/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:28:09 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/30 14:37:43 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_sprite(size_t *cnt, t_sprite *s, mlx_texture_t *t)
{
	free(cnt);
	free(s);
	mlx_delete_texture(t);
}

mlx_texture_t	*sprite_loop_m(mlx_texture_t *t_in, t_sprite in, size_t cnt[5])
{
	mlx_texture_t	*t;
	int32_t			q;

	t = create_sub_txt(in.width, in.height);
	if (cnt == NULL || t_in == NULL || t == NULL)
		return (NULL);
	set_var_m(cnt, &q, in, t_in->width);
	while (cnt[H] <= in.height)
	{
		while (cnt[W] < (in.width * BPP))
		{
			t->pixels[cnt[PX] + q] = t_in->pixels[cnt[INIT] - cnt[W] + q];
			set_q(cnt, &q);
		}
		set_var_m(cnt, &q, in, t_in->width);
	}
	return (t);
}

mlx_texture_t	*sprite_loop(mlx_texture_t *t_in, t_sprite in, size_t cnt[5])
{
	mlx_texture_t	*t;
	int32_t			q;

	t = create_sub_txt(in.width, in.height);
	if (cnt == NULL || t_in == NULL || t == NULL)
		return (NULL);
	set_var(cnt, &q, in, t_in->width);
	while (cnt[H] <= in.height)
	{
		while (cnt[W] < (in.width * BPP))
		{
			t->pixels[cnt[PX] + q] = t_in->pixels[cnt[INIT] + cnt[W] + q];
			set_q(cnt, &q);
		}
		set_var(cnt, &q, in, t_in->width);
	}
	return (t);
}

t_sprite	*create_sprite(mlx_texture_t *t, t_sprite in)
{
	t_sprite	*s;
	size_t		*cnt;

	cnt = NULL;
	s = NULL;
	if (in.count <= 0 || t == NULL)
		return (mlx_delete_texture(t), NULL);
	if (init_var(&cnt, &s, in) == 0)
		return (free_sprite(cnt, s, t), NULL);
	while (cnt[TXT] < in.count)
	{
		s->texture[cnt[TXT]] = sprite_loop(t, in, cnt);
		if (s->texture[cnt[TXT]] == NULL)
			return (NULL);
		cnt[TXT]++;
		cnt[PX] = 0;
		cnt[INIT] += in.width * BPP;
	}
	sprite_init(s, in);
	return (free_sprite(cnt, NULL, t), s);
}
