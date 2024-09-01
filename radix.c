/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:15:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/01 20:05:54 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	count_bits(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n >>= 1;
	}
	return i;
}
void	radix_sort_neg(t_stack **a, t_stack **b, int max)
{
	int	i;
	int	j;
	int	cnt;
	int	bit_max;
	int	bit_value;

	bit_max = count_bits(max);
	i = 0;
	while (i <= bit_max)
	{	
		cnt = stack_size(*a);
		j = 0;
		while (j++ < cnt)
		{
			bit_value = (*a)->n_value >> i;
			if (((bit_value & 1) == 0) && (*a)->n_value < 0)
				push(b, a, "pb");
			else
				rotate(a, "ra");
		}
		i++;
		while (*b != NULL)
			push(a, b , "pa");
	}
}

void	radix_sort_pos(t_stack **a, t_stack **b, int max)
{
	int	i;
	int	j;
	int	cnt;
	int	bit_max;
	int	bit_value;

	bit_max = count_bits(max);
	i = 0;
	while (i <= bit_max)
	{	
		cnt = stack_size(*a);
		j = 0;
		while (j++ < cnt)
		{
			bit_value = (*a)->value >> i;
			if (((bit_value & 1) == 0) && (*a)->value >= 0)
				push(b, a, "pb");
			else
				rotate(a, "ra");
		}
		i++;
		while (*b != NULL)
			push(a, b , "pa");
	}
}
