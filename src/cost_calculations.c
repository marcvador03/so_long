/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:59:53 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/19 13:19:24 by mfleury          ###   ########.fr       */
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
