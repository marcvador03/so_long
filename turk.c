/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/17 17:04:19 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_m_rotation(t_stack **a, t_stack **b, t_stack *target[2])
{
	t_spec	s[2];

	s[0] = fill_specs(*a, target[0]);
	s[1] = fill_specs(*b, target[1]);
	if (s[0].position > s[0].med && s[1].position > s[1].med)
	{
		while (s[0].size-- != s[0].position && s[1].size-- != s[1].position)
			double_r_rotate(a, b, "rrr"); // double rotation
		while (s[0].size-- != s[0].position - 1)
			r_rotate(a, "rra");
		while (s[1].size-- != s[1].position - 1)
			r_rotate(b, "rrb");
		return ;
	}
	else if (s[0].position <= s[0].med && s[1].position <= s[1].med)
	{
		while (s[0].position != 0 && s[1].position != 0)
			double_rotate(a, b, "rr"); // double rotation
		while (s[0].position != -1)
			rotate(a, "ra");
		while (s[1].position != -1)
			rotate(b, "rb");
		return ;
	}
	minimize_rotation(a, target[0], "rra");
	minimize_rotation(b, target[1], "rrb");
}

static int	minimize_cost(int *cnt, int med_a, int med_b)
{
	int	res;
	
	res = 0;
	if (cnt[0] > med_a && cnt[1] > med_b)
		res = max(cnt[0], cnt[1]);
	else if(cnt[0] > med_a && cnt[1] <= med_b)
		res = cnt[0] + cnt[1];	
	else if(cnt[0] <= med_a && cnt[1] > med_b)
		res = cnt[0] + cnt[1];	
	else if(cnt[0] <= med_a && cnt[1] <= med_b)
		res = max(cnt[0], cnt[1]);
	return (res);	
}

static void	update_cost(t_stack *a, t_stack *b, t_stack *target_b)
{
	int	cnt[2];
	t_spec	sa;
	t_spec	sb;

	a = a->head;
	b = b->head;
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
		a->cost = minimize_cost(cnt, sa.med, sb.med);
		cnt[0]++;	
		a = a->next;
	}
}

static void	define_target_a(t_stack *a, t_stack *target)
{
	unsigned int	min;

	a = a->head;
	min = a->cost;
	while (a != NULL)
	{		
		if (min > a->cost)
		{
			min = a->cost;
			target = a;	
		}
		a = a->next;
	}	
}

void	turk_sort(t_stack **a, t_stack *b)
{
	t_spec	sa;
	t_spec	sb;
	t_stack	*target[2];

	push(&b, a, "pb");
	push(&b, a, "pb");
	list_simple_display((*a)->head, b->head);
	while (stack_size(*a) > 3)
	{		
		sa = fill_specs(*a, NULL);
		sb = fill_specs(b, NULL);
		update_cost(*a, b, target[1]);
		define_target_a(*a, target[0]);
		min_m_rotation(a, &b, target);
		push(&b, a, "pb");
		list_simple_display((*a)->head, b->head);
	}
	insert_in_order(a, b, sa.n_min);
}	
