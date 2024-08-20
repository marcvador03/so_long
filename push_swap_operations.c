/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/20 18:12:01 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stk)
{
	t_stack *tmp;

	if (stk == NULL || stack_size(stk) == 1)
		exit (0);
	stk = stk->head;
	tmp = stk->next;
	stk->next = tmp->next;
	tmp->next = stk;
	stk = tmp;
	while (stk != NULL)
	{
		stk->head = tmp;
		stk = stk->next;
	}
}

void	push(t_stack **stk_a, t_stack *stk_b)
{
	if (stk_b == NULL)
		exit (0);
	*stk_a = (*stk_a)->head;
	stack_addfront(stk_a, stk_b->head, stk_b->value);
}

void	rotate(t_stack *stk)
{
	t_stack *tmp;
	
	stk = stack_last(stk);
	stk->next = stk->head;
	stk = stk->head;
	tmp = stk->next;
	stk->next = NULL;
	stk = tmp;
	while (stk != NULL)
	{
		stk->head = tmp;
		stk = stk->next;
	}
}

void	r_rotate(t_stack *stk)
{
	t_stack *tmp;
	
	tmp = stack_last(stk);
	stk = stk->head;
	tmp->next = stk;
	while (stk != tmp)
	{
		stk->head = tmp;
		stk = stk->next;
	}

}
