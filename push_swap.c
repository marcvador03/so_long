/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/20 11:10:31 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	void	*head;

	if (argc != 2)
		exit (0);
	i = 1;
	a = (t_stack *)malloc(sizeof (t_stack));
	b = (t_stack *)malloc(sizeof (t_stack));
	if (a == NULL || b == NULL)
		exit (0);
	a->value = ft_atoi(argv[1]);
	a->head = a;
	head = a;
	i = 0;
	while (i <= argc)
		stack_addback(a, head, ft_atoi(argv[i++]));
	list_full_display(a);
	return (0);
}
