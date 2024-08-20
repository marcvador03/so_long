/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:54:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/20 11:09:29 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_full_display(t_stack *stk)
{
	t_stack *tmp;
	int		i;

	tmp = stk->head;
	i = 1;
	while (tmp != NULL)
	{
		ft_printf("Rank: %d \n Value: %d \n Next Address: %p \n\n", i++, tmp->value, tmp->next); 
		tmp = tmp->next;
	}
}

void	list_display(t_stack *stk)
{
	ft_printf("Value: %d \n Next Address: %p \n\n", stk->value, stk->next); 
}
