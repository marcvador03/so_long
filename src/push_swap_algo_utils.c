/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:30:48 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/19 13:18:01 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	minimize_single_rotation(t_stack **stk, t_stack *target, char *prt)
{
	t_spec	s;

	s = fill_specs(*stk, target);
	if (s.rel_pos > s.med)
	{
		while (s.rel_pos != 0)
		{
			r_rotate(stk, prt);
			s = fill_specs(*stk, target);
		}
	}
	else
	{
		prt = prt + 1;
		while (s.rel_pos != 0)
		{
			rotate(stk, prt);
			s = fill_specs(*stk, target);
		}
	}
}

static void	inversed_rotation(t_stack **a, t_stack **b, t_stack *target[2])
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
		minimize_single_rotation(a, target[0], "rra");
	if (s[1].rel_pos != 0)
		minimize_single_rotation(b, target[1], "rrb");
}

static void	rotation(t_stack **a, t_stack **b, t_stack *target[2])
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
		minimize_single_rotation(a, target[0], "rra");
	if (s[1].rel_pos != 0)
		minimize_single_rotation(b, target[1], "rrb");
}

static char	*inverse_prt(char *prt)
{
	char	*res;

	res = NULL;
	if (ft_strncmp(prt, "rra", 3) == 0)
		res = "rrb";
	else if (ft_strncmp(prt, "rrb", 3) == 0)
		res = "rra";
	return (res);
}

void	multiple_move(t_stack **a, t_stack **b, t_stack *tgt[2], char *prt)
{
	t_spec	s[2];

	s[0] = fill_specs(*a, tgt[0]);
	s[1] = fill_specs(*b, tgt[1]);
	if (s[1].rel_pos == 0)
		minimize_single_rotation(a, tgt[0], prt);
	if (s[0].rel_pos == 0)
		minimize_single_rotation(b, tgt[1], inverse_prt(prt));
	s[0] = fill_specs(*a, tgt[0]);
	s[1] = fill_specs(*b, tgt[1]);
	if (s[0].rel_pos == 0 && s[1].rel_pos == 0)
		return ;
	if (s[0].rel_pos > s[0].med && s[1].rel_pos > s[1].med)
	{
		inversed_rotation(a, b, tgt);
		return ;
	}
	if (s[0].rel_pos <= s[0].med && s[1].rel_pos <= s[1].med)
		rotation(a, b, tgt);
	return ;
}
