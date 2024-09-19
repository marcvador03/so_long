/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:11:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/19 13:37:54 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	insert_in_order(t_stack **a, t_stack *b, unsigned int min)
{
	t_stack	*ptr;

	while (b != NULL)
	{
		ptr = search_next_big(b->n_value, min, *a);
		minimize_single_rotation(a, ptr, "rra");
		push(a, &b, "pa");
	}
}

void	sort_three(t_stack **a)
{
	t_spec	s;

	s = fill_specs(*a, NULL);
	if ((*a)->value == s.min)
	{
		rotate(a, "ra");
		if ((*a)->value == s.max)
			swap(a, "sa");
		r_rotate(a, "rra");
	}
	else if ((*a)->value == s.max)
	{
		rotate(a, "ra");
		if ((*a)->value != s.min)
			swap(a, "sa");
	}
	else
	{
		r_rotate(a, "rra");
		if ((*a)->value == s.max)
		{
			swap(a, "sa");
			r_rotate(a, "rra");
		}
	}
}

void	sort_five(t_stack **a, t_stack *b)
{
	t_spec	s;
	t_stack	*ptr;

	push(&b, a, "pb");
	if ((*a)->value > b->value)
		push(&b, a, "pb");
	else
	{
		push(&b, a, "pb");
		swap(&b, "sb");
	}
	sort_three(a);
	s = fill_specs(*a, NULL);
	insert_in_order(a, b, s.n_min);
	s = fill_specs(*a, NULL);
	ptr = search_value(s.min, *a);
	minimize_single_rotation(a, ptr, "rra");
}
