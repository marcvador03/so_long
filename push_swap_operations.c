/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/22 00:51:37 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	push(t_stack **head_o, t_stack **head_i)
{
	t_stack *tmp;

	if (*head_i == NULL)
		return ;
	stack_addfront(head_o, (*head_i)->value);
	tmp = *head_i;
	*head_i = tmp->next;
	tmp = NULL;
	free(tmp);
}

void	rotate(t_stack **head)
{
	t_stack *tmp;
	t_stack *tmp2;
	
	tmp = stack_last(*head);
	tmp->next = *head;
	tmp2 = (*head)->next;
	(*head)->next = NULL;
	*head = tmp2;
}

void	r_rotate(t_stack **head)
{
	t_stack *tmp;
	
	tmp = *head;
	*head = stack_last(tmp);
	(*head)->next = tmp;
	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->next == *head)
			tmp->next = NULL;
		tmp = tmp->next;
	}
}
