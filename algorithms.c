/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:11:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/16 18:27:25 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, int min, int max)
{
	if ((*a)->value == min)
	{
		rotate(a, "ra");
		if ((*a)->value == max)
			swap(a, "sa");
		r_rotate(a, "rra");
		return ;
	}
	else if ((*a)->value == max)
	{
		rotate(a, "ra");
		if ((*a)->value != min)
			swap(a, "sa");
		return ;
	}
	else
	{
		r_rotate(a, "rra");
		if ((*a)->value == max)
		{
			swap(a, "sa");
			r_rotate(a, "rra");
		}
		return ;
	}
}

void	sort_five(t_stack **a, t_stack *b)
{
	struct s_params	p;
	t_stack			*ptr;

	push(&b, a, "pb");
	if ((*a)->value > b->value)
		push(&b, a, "pb");
	else
	{
		push(&b, a, "pb");
		swap(&b, "sb");
	}
	fill_params(&p, *a);
	sort_three(&(*a)->head, p.min, p.max);
	insert_in_order(&(*a)->head, b->head, p.min);
	fill_params(&p, *a);
	ptr = search_value(p.min, &(*a)->head);
	a = &(*a)->head;
	while (*a != ptr && *a != NULL)
	{
		if (search_pos(p.med, p.min, (*a)->head) == -1)
			r_rotate(a, "rra");
		else
			rotate(a, "rra");
	}
}

/*void	min_sort(t_stack **a, int min, int max)
{
	t_stack	*b;
	int		tmp;

	b = (t_stack *)malloc(sizeof (t_stack));
	if (b == NULL)
		push_swap_exit ("Error\n", NULL, a);
	tmp = min;
	while ((*a)->value != min)
		rotate(a, "ra");
	push(&b, a, "pb");
	while ((*a)->next != NULL)
	{
		if ((*a)->value == max)
			rotate(a, "ra");
		else if (((*a)->value > b->value) && tmp == min)
			push(&b, a, "pb");
		else if ((((*a)->value > b->value)) && (*a)->value < tmp)
			push(&b, a, "pb");
		else if ((((*a)->value > b->value)) && (*a)->value > tmp)
		{
			r_rotate(&b, "rrb");
			r_rotate(&b, "rrb");
			tmp = b->value;
		}
		else if (((*a)->value < b->value) && (*a)->value > tmp)
		{
			tmp = b->value;
			rotate(&b, "rb");
		}
		else if (((*a)->value < b->value) && (*a)->value < tmp)
		{
			tmp = b->value;
			rotate(&b, "rb");
		}
	}
	while ((b->value) != min)
		rotate(&b, "rb");
	rotate(&b, "rb");
	while (b != NULL)
		push(a, &b, "pa");
}

void	selection_sort(t_stack **a)
{
	t_stack	*b;
	int		cnt;
	int		i;
	int		j;

	b = (t_stack *)malloc(sizeof (t_stack));
	if (b == NULL)
		push_swap_exit ("Error\n", NULL, a);
	cnt = stack_size(*a);
	j = 1;
	while (j++ <= cnt)
	{
		push(&b, a, "pb");
		i = 1;
		while (i++ < cnt)
		{
			if ((*a)->value > b->value)
			{
				push(a, &b, "pa");
				rotate(a, "ra");
				push(&b, a, "pb");
				i = 1;
			}
			else
			{
				rotate(a, "ra");
			}
		}
		push(a, &b, "pa");
		rotate(a, "ra");
	}
}*/
