/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:36:53 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/22 01:18:35 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **head_a, t_stack **head_b)
{
	t_stack *tmp;

	if (*head_b == NULL)
	{
		pb();
		list_simple_display(*head_a, *head_b);
	}
	tmp = *head_a;
	while (tmp != NULL)
	{
		if ((*head_b)->value < tmp->value)
		{
			pb();
			list_simple_display(*head_a, *head_b);
			tmp = *head_a;
		}
		else
			tmp = tmp->next;
	}
}
