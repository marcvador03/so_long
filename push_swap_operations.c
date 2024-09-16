/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/16 18:32:57 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stk, char *prt)
{
	t_stack	*tmp;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	tmp = (*stk)->next;
	(*stk)->next = tmp->next;
	tmp->next = *stk;
	*stk = tmp;
	(*stk)->head = tmp;
	stack_head_update(stk, &(*stk)->head);
	ft_printf("%s\n", prt);
}

void	push(t_stack **stk_o, t_stack **stk_i, char *prt)
{
	t_stack	*tmp;

	if (*stk_i == NULL)
		return ;
	tmp = (*stk_i)->next;
	(*stk_i)->next = *stk_o;
	*stk_o = *stk_i;
	*stk_i = tmp;
	(*stk_i)->head = *stk_i;
	stack_head_update(stk_i, &(*stk_i)->head);
	(*stk_o)->head = *stk_o;	
	stack_head_update(stk_o, &(*stk_o)->head);
	ft_printf("%s\n", prt);
}

void	rotate(t_stack **stk, char *prt)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_last(*stk);
	tmp->next = *stk;
	tmp2 = (*stk)->next;
	(*stk)->next = NULL;
	*stk = tmp2;
	(*stk)->head = tmp2;
	stack_head_update(stk, &(*stk)->head);
	ft_printf("%s\n", prt);
}

void	r_rotate(t_stack **stk, char *prt)
{
	t_stack	*tmp;

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
	(*stk)->head = *stk;
	stack_head_update(stk, &(*stk)->head);
	ft_printf("%s\n", prt);
}
