/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/22 00:27:27 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	t_stack	*head_a;
	t_stack	*head_b;

	if (argc < 1)
		exit (0);
	i = 1;
	a = (t_stack *)malloc(sizeof (t_stack));
	b = (t_stack *)malloc(sizeof (t_stack));
	if (a == NULL || b == NULL)
		exit (0);
	head_a = a;
	a->value = ft_atoi(argv[1]);
	a->next = NULL;
	head_b = NULL;
	i = 2;
	while (i < argc)
		stack_addback(&a, ft_atoi(argv[i++]));
	return (0);
}
