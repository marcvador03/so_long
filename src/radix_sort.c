/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:15:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 12:56:27 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	normalize_radix(t_stack **a, t_spec s)
{
	unsigned int	max;
	unsigned int	i;
	t_stack			*tmp;

	tmp = *a;
	max = stack_size(*a);
	while (tmp->n_value != s.n_min)
		tmp = tmp->next;
	*a = tmp;
	(*a)->r_value = max;
	i = max - 1;
	while (i > 0)
	{
		*a = search_next_big((*a)->n_value, s.n_min, *a);
		(*a)->r_value = i--;
	}
	*a = (*a)->head;
}

static int	count_bits(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n >>= 1;
	}
	return (i);
}

void	radix_sort(t_stack **a, t_stack *b)
{
	int		i;
	int		j;
	int		bit_max;
	int		bit_value;
	t_spec	s;

	s = fill_specs(*a, NULL);
	normalize_radix(a, s);
	i = 0;
	bit_max = count_bits(stack_size(*a));
	while (i <= bit_max)
	{
		j = 0;
		while (j++ < s.size)
		{
			bit_value = (*a)->r_value >> i;
			if ((bit_value & 1) == 1)
				push(&b, a, "pb");
			else
				rotate(a, "ra");
		}
		i++;
		while (b != NULL)
			push(a, &b, "pa");
	}
}
