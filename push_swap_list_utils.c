/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:37:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/19 17:09:17 by mfleury          ###   ########.fr       */
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

void	stack_addback(t_stack *stk, void *head, int value)
{
	t_stack	*tmp;

	if (stk != NULL)
	{
		tmp = stack_last(stk);
		tmp->value = value;
		tmp->prev = stk;
		tmp->next = NULL;
		tmp->head = head;
	}
}

t_stack	*stack_new(char *value)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof (t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->value = ft_atoi(value);
	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->head = ptr;
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

void	stack_addfront(t_stack **stk, t_stack *new_node)
{
	if (stk != 0 && new_node != 0)
	{
		new_node->next = *stk;
		*stk = new_node;
	}
}
