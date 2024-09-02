/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/02 23:34:31 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	stack_free(t_stack **stk)
{
	t_stack *tmp;

	while (*stk != NULL)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = tmp;
	}
}

void	args_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}

static void	stk_sorted(t_stack **a)
{
	int	prev;
	t_stack	*head;

	head = *a;
	prev = (*a)->value;
	while (*a != NULL)
	{
		if (prev <= (*a)->value)
		{
			prev = (*a)->value;
			*a = (*a)->next;
		}
		else
		{
			*a = head; 
			return;
		}
	}
	stack_free(&head);
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
	t_stack	*head_a;
	char	**args;
	struct	s_params p;

	if (argc < 1)
		exit (0);
	if (argc == 1)
		args = ft_split(argv[1], ' ');
	else
		args = argv;   
	ps_parse(args);
	args_free(args);
	stk_sorted(&head_a);
	normalize_neg(a, min);
//	selection_sort(&head_a);
//	min_sort(&head_a, min, max);
	if(stack_size(head_a) == 3)
		sort_three(&head_a, min, max);
	else
		radix_sort(&head_a, max);
	//list_simple_display(head_a, NULL);	
	stack_free(&head_a);
	return (0);
}
