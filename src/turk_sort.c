/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/19 13:22:51 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	turk_insert_a(t_stack **a, t_stack **b, int rem)
{
	t_stack	*target[2];

	target[0] = NULL;
	target[1] = NULL;
	while (stack_size(*b) > rem && *b != NULL)
	{
		update_cost_max(*b, *a);
		define_mincost_targets(*b, target);
		multiple_move(b, a, target, "rrb");
		minimize_single_rotation(a, target[1], "rra");
		minimize_single_rotation(b, target[0], "rrb");
		push(a, b, "pa");
	}
}

static void	turk_insert_b(t_stack **b, t_stack **a, int rem)
{
	t_stack	*target[2];

	target[0] = NULL;
	target[1] = NULL;
	while (stack_size(*a) > rem && *a != NULL)
	{
		update_cost_min(*a, *b);
		define_mincost_targets(*a, target);
		multiple_move(a, b, target, "rra");
		minimize_single_rotation(a, target[0], "rra");
		minimize_single_rotation(b, target[1], "rrb");
		push(b, a, "pb");
	}
}

void	turk_sort(t_stack **a, t_stack *b)
{
	t_spec	sa;

	push(&b, a, "pb");
	push(&b, a, "pb");
	turk_insert_b(&b, a, 3);
	sort_three(a);
	turk_insert_a(a, &b, 0);
	sa = fill_specs(*a, NULL);
	minimize_single_rotation(a, search_value(sa.min, *a), "rra");
}
