/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/01 20:10:18 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	stk_sorted(t_stack *a)
{
	int	prev;

	prev = a->value;
	while (a != NULL)
	{
		if (prev <= a->value)
		{
			prev = a->value;
			a = a->next;
		}
		else
			return;
	}
	exit(0);
}

static void	normalize_neg(t_stack *a, int min)
{
	while (a != NULL)
	{
		if (a->value < 0)
			a->n_value = a->value + min;
		a = a->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;
	int		min;
	int		max;
	int n;

	if (argc < 1)
		exit (0);
	i = 1;
	a = (t_stack *)malloc(sizeof (t_stack));
	b = (t_stack *)malloc(sizeof (t_stack));
	if (a == NULL || b == NULL)
		exit (0);
	head_a = a;
	head_b = NULL;
	a->value = ft_atoi(argv[1]);
	min = a->value;
	max = a->value;
	a->next = NULL;
	i = 2;
	while (i < argc)
	{
		n = ft_atoi(argv[i++]);
		stack_addback(&a, n, n);
		if (n > max)
			max = n;
		if (n < min)
			min = n;
	}
	stk_sorted(a);
	normalize_neg(a, min);
//	selection_sort(&head_a, &head_b);
//	min_sort(&head_a, &head_b, min, max);
	radix_sort_neg(&head_a, &head_b, max);
	radix_sort_pos(&head_a, &head_b, max);
	list_simple_display(head_a, head_b);	
	free(a);
	free(b);
	return (0);
}
