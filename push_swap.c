/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/28 20:08:57 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;
	int		args[2];;
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
	args[0] = a->value;
	args[1] = a->value;
	a->next = NULL;
	i = 2;
	while (i < argc)
	{
		n = ft_atoi(argv[i++]);
		stack_addback(&a, n);
		if (n > args[1])
			args[1] = n;
		if (n < args[0])
			args[0] = n;
	}
//	selection_sort(&head_a, &head_b);
	min_sort(&head_a, &head_b, args);
	//list_simple_display(a, b);	
	free(a);
	free(b);
	return (0);
}
