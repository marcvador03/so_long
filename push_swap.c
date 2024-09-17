/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 00:49:14 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*void	stack_free(t_stack **stk)
{
	t_stack	*tmp;

	while (*stk != NULL)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = tmp;
	}
}*/
int		search_min(t_stack *stk)
{
	int	min;

	stk = stk->head;
	while (stk != NULL)
	{
		if (min > stk->value || stk == stk->head)
			min = stk->value;
		stk = stk->next;
	}
	return (min);
}


void	push_swap_exit(char *prt, char **args, t_stack **stk)
{
	t_stack	*tmp;
	int		i;

	if (prt != NULL)
		write(2, prt, ft_strlen(prt));
	if (args != NULL)
	{
		i = 0;
		while (args[i] != NULL)
			free(args[i++]);
		free(args);
	}
	if (stk != NULL)
	{
		while (*stk != NULL)
		{
			tmp = (*stk)->next;
			free(*stk);
			*stk = tmp;
		}
		free(*stk);
	}
	exit(1);
}

static void	stk_sorted(t_stack *a)
{
	int		prev;

	prev = a->value;
	while (a != NULL)
	{
		if (prev <= a->value)
		{
			prev = a->value;
			a = a->next;
		}
		else
			return ;
	}
	push_swap_exit(NULL, NULL, &a->head);
}

static void	normalize_neg(t_stack *a, int min)
{
	while (a != NULL)
	{
		if (min < 0)
			a->n_value = a->value - min;
		else
			a->n_value = a->value;
		a = a->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		exit (0);
	if (argc == 2)
		a = ps_parse_split(argv[1], ' ');
	else
		a = ps_parse(argv + 1);
	b = NULL;
	stk_sorted(a->head);
	normalize_neg(a->head, search_min(a));
//	selection_sort(&head_a);
//	min_sort(&head_a, min, max);
	a = a->head;
	if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 5)
		sort_five(&a, b);
	else
		radix_sort(&a, NULL);
		//turk_sort(&a, b);
	push_swap_exit(NULL, NULL, &a->head);
	return (0);
}
