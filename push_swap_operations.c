/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/28 19:35:01 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stk)
{
	t_stack *tmp;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	tmp = (*stk)->next;
	(*stk)->next = tmp->next;
	tmp->next = *stk;
	*stk = tmp;
}

void	push(t_stack **stk_o, t_stack **stk_i)
{
	t_stack *tmp;

	if (*stk_i == NULL)
		return ;
	stack_addfront(stk_o, (*stk_i)->value);
	tmp = *stk_i;
	*stk_i = tmp->next;
	tmp = NULL;
	free(tmp);
}

void	rotate(t_stack **stk)
{
	t_stack *tmp;
	t_stack *tmp2;
	
	tmp = stack_last(*stk);
	tmp->next = *stk;
	tmp2 = (*stk)->next;
	(*stk)->next = NULL;
	*stk = tmp2;
}

void	r_rotate(t_stack **stk)
{
	t_stack *tmp;
	
	tmp = *stk;
	*stk = stack_last(tmp);
	(*stk)->next = tmp;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (tmp->next == *stk)
			tmp->next = NULL;
		tmp = tmp->next;
	}
}
