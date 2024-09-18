/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:56:33 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 12:07:46 by mfleury          ###   ########.fr       */
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

static t_stack	*search_n_value(unsigned int n, t_stack *stk)
{
	while (stk != NULL)
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

int	search_pos(t_stack *target, t_stack *stk)
{
	int	i;

	if (target == NULL)
		return (0);
	i = 0;
	while (stk != target && stk != NULL)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}
