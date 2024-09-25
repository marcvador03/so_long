/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:37:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 22:51:34 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stack_last(t_stack *stk)
{
	t_stack	*tmp;

	if (stk == NULL)
		return (NULL);
	tmp = stk;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	stack_addback(t_stack **stk, int value, int n_value)
{
	t_stack	*tmp;

	if (*stk == NULL)
		*stk = stack_new(value, n_value, NULL);
	else if (*stk != NULL)
	{
		tmp = stack_new(value, n_value, (*stk)->head);
		*stk = stack_last(*stk);
		(*stk)->next = tmp;
	}
}

t_stack	*stack_new(int value, int n_value, t_stack *head)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof (t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->value = value;
	ptr->n_value = n_value;
	ptr->next = NULL;
	ptr->target = NULL;
	if (head == NULL)
		ptr->head = ptr;
	else
		ptr->head = head;
	return (ptr);
}

int	stack_size(t_stack *stk)
{
	int		cnt;
	t_stack	*tmp;

	if (stk == NULL)
		return (0);
	cnt = 0;
	tmp = stk->head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

void	stack_head_update(t_stack *stk, t_stack *head)
{
	stk = head;
	while (stk != NULL)
	{
		stk->head = head;
		stk = stk->next;
	}
}
