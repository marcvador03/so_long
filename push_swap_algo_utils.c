/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:30:48 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/16 15:36:56 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*search_value(int n, t_stack **stk)
{
	t_stack	*tmp;

	tmp = *stk;
	while (tmp != NULL)
	{
		if (tmp->value == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_stack	*search_next_big(unsigned int n, int min, t_stack *stk)
{
	unsigned int	diff;
	t_stack			*head_stk;
	t_stack			*res;

	head_stk = stk;
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
		return (search_value(min, &head_stk));
	return (res);
}

void	insert_in_order(t_stack **a, t_stack *b, int min)
{
	t_stack	*ptr;

	while (b != NULL)
	{
		ptr = search_next_big(b->n_value, min, *a);
		while (*a != ptr && *a != NULL)
		{
			rotate(a, "ra");
		}
		push(a, &b, "pa");
		//b = b->next;
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
