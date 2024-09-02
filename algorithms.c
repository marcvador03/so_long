/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:56:51 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/02 22:36:58 by mfleury          ###   ########.fr       */
/*                             args[0]                                            */
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
		return;
	}
	else if ((*a)->value == max)
	{
		rotate(a, "ra");
		if ((*a)->value != min)
			swap(a, "sa");
		return;
	}
	else
	{
		r_rotate(a, "rra");
		if ((*a)->value == max)
		{
			swap(a, "sa");
			r_rotate(a, "rra");
		}
		return;
	}
}
void	min_sort(t_stack **a, int min, int max)
{
	t_stack	*b;
	int	tmp;

	b = (t_stack *)malloc(sizeof (t_stack));
	if (b == NULL)
		exit (0);
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
	int	cnt;
	int	i;
	int	j;

	b = (t_stack *)malloc(sizeof (t_stack));
	if (b == NULL)
		exit (0);
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
}
