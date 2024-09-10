/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:39:02 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/10 11:09:52 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_rgba(int r, int g, int b, int a)
{
	 return (r << 24 | g << 16 | b << 8 | a);
}

int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int	get_a(int rgba)
{
	return (rgba & 0xFF);
}

int	get_neg_color(int color)
{
	int	r;
	int	g;
	int	b;

	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_rgba(r, g, b, get_a(color)));	
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
	return (create_rgba(r, g, b, get_a(color)));	
}
