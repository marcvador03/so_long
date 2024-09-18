/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:30:48 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 12:57:00 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	minimize_rotation(t_stack **stk, t_stack *target, char *prt)
{
	t_spec	s;

	s = fill_specs(*stk, target);
	if (s.position > s.med)
	{
		while (s.size-- != s.position)
			r_rotate(stk, prt);
	}
	else
	{
		prt = prt + 1;
		while (s.position-- != 0)
			rotate(stk, prt);
	}
}

void	min_multiple_rotation(t_stack **a, t_stack **b, t_stack *target[2])
{
	t_spec	s[2];

	s[0] = fill_specs(*a, target[0]);
	s[1] = fill_specs(*b, target[1]);
	if (s[0].position > s[0].med && s[1].position > s[1].med)
	{
		while (s[0].size-- != s[0].position && s[1].size-- != s[1].position)
			double_rotate(a, b, "rrr", 1);
		while (s[0].size-- != s[0].position - 1)
			r_rotate(a, "rra");
		while (s[1].size-- != s[1].position - 1)
			r_rotate(b, "rrb");
	}
	else if (s[0].position <= s[0].med && s[1].position <= s[1].med)
	{
		while (s[0].position-- != 0 && s[1].position-- != 0)
			double_rotate(a, b, "rr", 0);
		while (s[0].position-- != -1)
			rotate(a, "ra");
		while (s[1].position-- != -1)
			rotate(b, "rb");
	}
	minimize_rotation(a, target[0], "rra");
	minimize_rotation(b, target[1], "rrb");
}

void	insert_in_order(t_stack **a, t_stack *b, unsigned int min)
{
	t_stack	*ptr;

	while (b != NULL)
	{
		ptr = search_next_big(b->n_value, min, *a);
		minimize_rotation(a, ptr, "rra");
		push(a, &b, "pa");
	}
}
