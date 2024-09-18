/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:30:48 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 23:59:49 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void 	inversed_rotation(t_stack **a, t_stack **b, t_stack *target[2])
{
	t_spec	s[2];

	s[0] = fill_specs(*a, target[0]);
	s[1] = fill_specs(*b, target[1]);
	while (s[0].rel_pos != 0 && s[1].rel_pos != 0)
	{
		double_rotate(a, b, "rrr", 1);
		s[0] = fill_specs(*a, target[0]);
		s[1] = fill_specs(*b, target[1]);
	}
	if (s[0].rel_pos != 0)
		minimize_rotation(a, target[0], "rra");
	if (s[1].rel_pos != 0)
		minimize_rotation(b, target[1], "rrb");
}

static void 	rotation(t_stack **a, t_stack **b, t_stack *target[2])
{
	t_spec	s[2];

	s[0] = fill_specs(*a, target[0]);
	s[1] = fill_specs(*b, target[1]);
	while (s[0].rel_pos != 0 && s[1].rel_pos != 0)
	{
		double_rotate(a, b, "rr", 0);
		s[0] = fill_specs(*a, target[0]);
		s[1] = fill_specs(*b, target[1]);
	}
	if (s[0].rel_pos != 0)
		minimize_rotation(a, target[0], "rra");
	if (s[1].rel_pos != 0)
		minimize_rotation(b, target[1], "rrb");
}

void	min_multiple_rotation(t_stack **a, t_stack **b, t_stack *target[2])
{
	t_spec	s[2];

	s[0] = fill_specs(*a, target[0]);
	s[1] = fill_specs(*b, target[1]);
	if (s[0].rel_pos == 0)
		minimize_rotation(a, target[0], "rra");
	if (s[1].rel_pos == 0)
		minimize_rotation(b, target[1], "rrb");
	s[0] = fill_specs(*a, target[0]);
	s[1] = fill_specs(*b, target[1]);
	if (s[0].rel_pos == 0 && s[1].rel_pos == 0)
		return;
	if (s[0].rel_pos > s[0].med && s[1].rel_pos > s[1].med)
	{
		inversed_rotation(a, b, target);
		return ;
	}
	if (s[0].rel_pos <= s[0].med && s[1].rel_pos <= s[1].med)
	{
		rotation(a, b, target);
		return ;
	}
}
