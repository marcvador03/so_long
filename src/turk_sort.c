/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 23:21:08 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	define_mincost_targets(t_stack *stk, t_stack **target)
{
	unsigned int	min;

	stk = stk->head;
	min = stk->cost;
	target[0] = stk;
	target[1] = stk->target;
	while (stk != NULL)
	{
		if (min > stk->cost)
		{
			min = stk->cost;
			target[0] = stk;
			target[1] = stk->target;
		}
		if (min == 0)
			return ; 
		stk = stk->next;
	}
}

static void	turk_insert_a(t_stack **a, t_stack **b, int rem)
{
	t_stack	*target[2];
	
	target[0] = NULL;
	target[1] = NULL;
	while (stack_size(*b) > rem && *b != NULL)
	{
		update_cost_max(*b, *a);	
		define_mincost_targets(*b, target);
		min_multiple_rotation(b, a, target);
		minimize_rotation(a, target[0], "rra");
		minimize_rotation(b, target[1], "rrb");
		push(a, b, "pa");
		list_display(*a, *b);
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
		min_multiple_rotation(a, b, target);
		minimize_rotation(a, target[0], "rra");
		minimize_rotation(b, target[1], "rrb");
		push(b, a, "pb");
		list_display(*a, *b);
	}		
}

void	turk_sort(t_stack **a, t_stack *b)
{
	t_spec	sa;

	push(&b, a, "pb");
	push(&b, a, "pb");
	list_display(*a, b);
	turk_insert_b(&b, a, 3);
	sort_three(a);
	turk_insert_a(a, &b, 0);
	sa = fill_specs(*a, NULL);
	minimize_rotation(a, search_value(sa.min, *a), "rra");
}
