/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:56:51 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/28 20:09:37 by mfleury          ###   ########.fr       */
/*                             args[0]                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_sort(t_stack **a, t_stack **b, int args[2])
{
	int	tmp;

	tmp = args[0];
	while ((*a)->value != args[0])
	{
		ra();	
	}
	pb();
	while ((*a)->next != NULL)
	{
		if ((*a)->value == args[1])
		{
			ra();
		}
		else if (((*a)->value > (*b)->value) && tmp == args[0])
		{
			pb();
		}
		else if ((((*a)->value > (*b)->value)) && (*a)->value < tmp)
		{
			pb();
		}
		else if ((((*a)->value > (*b)->value)) && (*a)->value > tmp)
		{
			rrb();
			rrb();
			tmp = (*b)->value;
		}
		else if (((*a)->value < (*b)->value) && (*a)->value > tmp)
		{
			tmp = (*b)->value;
			rb();
		}
		else if (((*a)->value < (*b)->value) && (*a)->value < tmp)
		{
			tmp = (*b)->value;
			rb();
		}
	}	
	while (((*b)->value) != args[0])
	{
		rb();
	}
	rb();
	while (*b != NULL)
	{
		pa();
	}
}
void	selection_sort(t_stack **a, t_stack **b)
{
	int	cnt;
	int	i;
	int	j;

	cnt = stack_size(*a);
	j = 1;
	while (j++ <= cnt)
	{
		pb();
		i = 1;
		while (i++ < cnt)
		{
			if ((*a)->value > (*b)->value)
			{
				pa();
				ra();
				pb();
				i = 1;
			}
			else
			{
				ra();
			}
		}
		pa();
		ra();
	}
}
