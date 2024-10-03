/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:28:09 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/03 21:43:29 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_sprite(size_t *cnt, t_sprite *s, mlx_texture_t *t)
{
	free(cnt);
	free(s);
	mlx_delete_texture(t);
}

static mlx_texture_t	*loop_m(mlx_texture_t *t_in, t_sprite in, size_t cnt[5])
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

static mlx_texture_t	*loop(mlx_texture_t *t_in, t_sprite in, size_t cnt[5])
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

t_sprite	*create_sprite_m(t_win *sl, mlx_texture_t *t, t_sprite in)
{
	t_sprite	*s;
	size_t		*cnt;

	cnt = NULL;
	s = NULL;
	if (in.count <= 0 || t == NULL)
		s_err(sl, NULL, NULL, t);
	if (init_var(&cnt, &s, in) == 0)
		s_err(sl, cnt, s, t);
	while (cnt[TXT] < in.count)
	{
		s->texture[cnt[TXT]] = loop_m(t, in, cnt);
		if (s->texture[cnt[TXT]] == NULL)
			s_err(sl, cnt, s, t);
		cnt[TXT]++;
		cnt[PX] = 0;
		cnt[H] = 0;
	}
	sprite_init(s, in);
	return (free_sprite(cnt, NULL, t), s);
}

t_sprite	*create_sprite(t_win *sl, mlx_texture_t *t, t_sprite in)
{
	t_sprite	*s;
	size_t		*cnt;

	cnt = NULL;
	s = NULL;
	if (in.count <= 0 || t == NULL)
		s_err(sl, NULL, NULL, t);
	if (init_var(&cnt, &s, in) == 0)
		s_err(sl, cnt, s, t);
	while (cnt[TXT] < in.count)
	{
		s->texture[cnt[TXT]] = loop(t, in, cnt);
		if (s->texture[cnt[TXT]] == NULL)
			s_err(sl, cnt, s, t);
		cnt[TXT]++;
		cnt[PX] = 0;
		cnt[H] = 0;
	}
	sprite_init(s, in);
	return (free_sprite(cnt, NULL, t), s);
}
