/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:59:53 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 23:59:47 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	minimize_rotation(t_stack **stk, t_stack *target, char *prt)
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

/*int	min_multiple_rotation(t_stack **a, t_stack **b, t_stack *target[2])
{
	t_spec	s[2];

	s[0] = fill_specs(*a, target[0]);
	s[1] = fill_specs(*b, target[1]);
	if (s[0].rel_pos > s[0].med && s[1].rel_pos > s[1].med)
	{
		while (s[0].size-- != s[0].rel_pos && s[1].size-- != s[1].rel_pos)
			double_rotate(a, b, "rrr", 1);
		while (s[0].size-- != s[0].rel_pos - 1)
			r_rotate(a, "rra");
		while (s[1].size-- != s[1].rel_pos - 1)
			r_rotate(b, "rrb");
	}
	else if (s[0].rel_pos <= s[0].med && s[1].rel_pos <= s[1].med)
	{
		while (s[0].rel_pos-- != 0 && s[1].rel_pos-- != 0)
			double_rotate(a, b, "rr", 0);
		while (s[0].rel_pos-- != -1)
			rotate(a, "ra");
		while (s[1].rel_pos-- != -1)
			rotate(b, "rb");
	}
	else
		return (0);
	return (1);
}*/

static int	minimize_cost(int *cnt, t_spec *sa, t_spec *sb)
{
	int	res;

	res = cnt[0] + cnt[1];
	if (sa->size - cnt[0] < cnt[0])
	{
		if (cnt[1] == 0)
			res = sa->size - cnt[0];
		else if (sb->size - cnt[1] < cnt[1])
			res = max(sa->size - cnt[0], sb->size - cnt[1]);
	}
	if (sb->size - cnt[1] < cnt[1])
	{
		if (cnt[0] == 0)
			res = sb->size - cnt[1];
		else if (sa->size - cnt[0] < cnt[0])
			res = max(sa->size - cnt[0], sb->size - cnt[1]);
	}
	if (sa->size - cnt[0] >= cnt[0])
		if (cnt[1] == 0 || sb->size - cnt[1] >= cnt[1])
			res = max(cnt[0], cnt[1]);
	if (sb->size - cnt[1] >= cnt[1])
		if (cnt[0] == 0 || sa->size - cnt[0] >= cnt[0])
			res = max(cnt[0], cnt[1]);
	return (res);
}

void	update_cost_min(t_stack *a, t_stack *b)
{
	int		cnt[2];
	t_spec	sa;
	t_spec	sb;
	t_stack	*target_b;

	a = a->head;
	target_b = NULL;
	sa = fill_specs(a, NULL);
	sb = fill_specs(b, NULL);
	cnt[0] = 0;
	while (a != NULL)
	{
		target_b = search_next_small(a->n_value, sb.n_max, b);
		cnt[1] = 0;
		b = b->head;
		while (b != target_b && b != NULL)
		{
			cnt[1]++;
			b = b->next;
		}
		a->target = b;
		a->cost = minimize_cost(cnt, &sa, &sb);
		cnt[0]++;
		a = a->next;
	}
}

void	update_cost_max(t_stack *b, t_stack *a)
{
	int		cnt[2];
	t_spec	sa;
	t_spec	sb;
	t_stack	*target_a;

	b = b->head;
	target_a = NULL;
	sa = fill_specs(a, NULL);
	sb = fill_specs(b, NULL);
	cnt[0] = 0;
	while (b != NULL)
	{
		target_a = search_next_big(b->n_value, sa.n_min, a);
		cnt[1] = 0;
		a = a->head;
		while (a != target_a && a != NULL)
		{
			cnt[1]++;
			a = a->next;
		}
		b->target = a;
		b->cost = minimize_cost(cnt, &sb, &sa);
		cnt[0]++;
		b = b->next;
	}
}
