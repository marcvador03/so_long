/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:26:16 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/17 15:22:34 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

int	max(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}
