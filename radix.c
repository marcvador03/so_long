/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:15:15 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/01 14:10:55 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*static void	normalize_radix(t_stack **a, int min, int max)
{
	int *val;
	int	cnt;
	int	i;

	cnt = stack_size(*a);
	val = (int *)malloc(cnt * sizeof(int));
	i = 0;
	while (i <= cnt)
	{
	}
	
	free(val);


}*/
void	radix_sort(t_stack **a, t_stack **b, int min, int max)
{
	int	i;
	int	j;
	int	cnt;
	int	bit_max;

	bit_max = 8 * sizeof(max);
	i = 0;
	while (i <= bit_max)
	{	
		(*a)->value >>= i++;
		cnt = stack_size(*a);
		j = 0;
		while (j++ <= cnt)
		{
			if ((((*a)->value & 1) == 1) && (*a)->value >= 0)
				push(b, a, "pb");
			else
				rotate(a, "ra");
		}
		while (b != NULL)
		{
			push(a, b , "pa");
			*b = (*b)->next;
		}
	}
}
