/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:30:48 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/17 20:42:39 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*search_value(int n, t_stack *stk)
{
	while (stk != NULL)
	{
		if (stk->value == n)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

t_stack	*search_n_value(unsigned int n, t_stack *stk)
{
	while (stk!= NULL)
	{
		if (stk->n_value == n)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

t_stack	*search_next_big(unsigned int n, unsigned int min, t_stack *stk)
{
	unsigned int	diff;
	t_stack			*res;
	t_stack			*head;

	stk = stk->head;
	head = stk->head;
	diff = 0;
	res = NULL;
	while (stk != NULL)
	{
		if (stk->n_value > n && (diff == 0 || (stk->n_value - n) < diff))
		{
			diff = stk->n_value - n;
			res = stk;
		}
		stk = stk->next;
	}
	if (diff == 0)
		return (search_n_value(min, head));
	return (res);
}

t_stack	*search_next_small(unsigned int n, unsigned int max, t_stack *stk)
{
	unsigned int	diff;
	t_stack			*res;
	t_stack			*head;

	stk = stk->head;
	head = stk->head;
	diff = 0;
	res = NULL;
	while (stk != NULL)
	{
		if (stk->n_value < n && (diff == 0 || (n - stk->n_value) < diff))
		{
			diff = n - stk->n_value;
			res = stk;
		}
		stk = stk->next;
	}
	if (diff == 0)
		return (search_n_value(max, head));
	return (res);
}

void	insert_in_order(t_stack **a, t_stack *b, unsigned int min)
{
	t_stack	*ptr;
	//t_spec	s;

	//s = fill_specs(*a, NULL);
	while (b != NULL)
	{
		ptr = search_next_big(b->n_value, min, *a);
		minimize_rotation(a, ptr, "rra");
		push(a, &b, "pa");
	}
}

/*void	insert_reverse_order(t_stack **a, t_stack *b, int max)
{
	void	*ptr;
	
	while (b != NULL)
	{
		ptr = search_next_small(b->n_value, max, *a);
		while (*a != ptr || *a != NULL)
		{
			rotate(a, "ra");
			(*a) = (*a)->next;
		}
		b = b->next;
	}
}*/
