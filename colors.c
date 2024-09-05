/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:39:02 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/05 15:15:31 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	 return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);

}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);

}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	get_neg_color(int color)
{
	int	r;
	int	g;
	int	b;

	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_trgb(get_t(color), r, g, b));	
}

int	add_shade(int color, double d)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	if (r >= (d * 0xFF))
		r = r - (d * 0xFF);
	else
		r = 0;
	if (g >= (d * 0xFF))
		g = g - (d * 0xFF);
	else
		g = 0;
	if (b >= (d * 0xFF))
		b = b - (d * 0xFF);
	else
		b = 0;
	return (create_trgb(get_t(color), r, g, b));	
}
