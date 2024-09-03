/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/03 13:08:26 by mfleury          ###   ########.fr       */
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

void	push_swap_exit(char *prt, char **args, t_stack **stk)
{
	t_stack *tmp;
	int		i;
	
	if (prt != NULL)
	{
		i = 0;
		while (prt[i] != '\0')
			write(2, &prt[i++], 1);
	}
	if (args != NULL)
	{
		i = 0;
		while (args[i] != NULL)
			free(args[i++]);
	}
	if (stk != NULL)
	{
		while (*stk != NULL)
		{
			tmp = (*stk)->next;
			free(*stk);
			*stk = tmp;
		}
	}
	free(args);
	free(stk);
	exit(1);
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
	push_swap_exit(NULL, NULL, &head);
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
	struct	s_params p;

	if (argc < 1)
		exit (0);
	if (argc == 1)
		a = ps_parse_split(argv[1], ' ');
	else
		a = ps_parse(argv);
	head_a = a;
	stk_sorted(&head_a);
	fill_params(&p, head_a);
	normalize_neg(a, p.min);
//	selection_sort(&head_a);
//	min_sort(&head_a, min, max);
	if(stack_size(head_a) == 3)
		sort_three(&head_a, p.min, p.max);
	else
		radix_sort(&head_a, p.max);
	//list_simple_display(head_a, NULL);	
	push_swap_exit(NULL, NULL, &head_a);
	return (0);
}
