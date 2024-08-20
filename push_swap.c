/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/20 18:17:24 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	void	*head;

	if (argc < 1)
		exit (0);
	i = 1;
	a = (t_stack *)malloc(sizeof (t_stack));
	b = (t_stack *)malloc(sizeof (t_stack));
	if (a == NULL || b == NULL)
		exit (0);
	head = a;
	a->value = ft_atoi(argv[1]);
	a->head = head;
	a->next = NULL;
	i = 2;
	while (i < argc)
		stack_addback(&a, head, ft_atoi(argv[i++]));
	list_full_display(a);
	return (0);
}
