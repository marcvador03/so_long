/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:26:16 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 12:06:51 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_spec	fill_specs(t_stack *stk, t_stack *target)
{
	t_spec	s;

	s.size = stack_size(stk);
	s.position = search_pos(target, stk);
	stk = stk->head;
	s.min = stk->value;
	s.max = stk->value;
	while (stk != NULL)
	{
		if (s.min > stk->value)
		{
			s.min = stk->value;
			s.n_min = stk->n_value;
		}
		if (s.max < stk->value)
		{
			s.max = stk->value;
			s.n_max = stk->n_value;
		}
		stk = stk->next;
	}
	s.med = s.size / 2;
	return (s);
}

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
