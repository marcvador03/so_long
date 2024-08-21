/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:37:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/21 23:36:58 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_addback(t_stack **stk, int value)
{
	t_stack	*tmp;

	if (*stk == NULL)
		*stk = stack_new(value);
	else if (*stk != NULL)
	{
		tmp = stack_new(value);
		*stk = stack_last(*stk);
		(*stk)->next = tmp;
	}
}

void	stack_addfront(t_stack **head, int value)
{
	t_stack	*tmp;
		
	if (*head == NULL)
		*head = stack_new(value);
	else if (*head != NULL)
	{
		tmp = stack_new(value);
		tmp->next = *head;
		*head = tmp;
	}
}

t_stack	*stack_new(int value)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof (t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
}

int	stack_size(t_stack *stk)
{
	int		cnt;
	t_stack	*tmp;

	cnt = 0;
	tmp = stk;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

