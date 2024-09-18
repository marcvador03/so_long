/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 23:11:11 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	stack_free(t_stack *stk)
{
	t_stack	*tmp;

	stk = stk->head;
	while (stk != NULL)
	{
		tmp = stk->next;
		free(stk);
		stk = tmp;
	}
}

void	push_swap_exit(char *prt, char **args, t_stack **a, t_stack **b)
{
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
	if (a != NULL)
		stack_free(*a);
	if (b != NULL)
		stack_free(*b);
	exit(1);
}

static void	stk_sorted(t_stack *a)
{
	int		prev;
	t_stack	*head;

	head = a->head;
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
	a = head;
	push_swap_exit(NULL, NULL, &a, NULL);
}

static void	normalize_negative_int(t_stack *a)
{
	int		min;
	t_stack	*head;

	head = a;
	min = a->value;
	while (a != NULL)
	{
		if (min > a->value)
			min = a->value;
		a = a->next;
	}
	a = head;
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

	if (argc <= 1)
		exit (0);
	if (argc == 2)
		a = ps_parse_split(argv[1], ' ');
	else
		a = ps_parse(argv + 1);
	stk_sorted(a->head);
	normalize_negative_int(a->head);
	a = a->head;
	if (stack_size(a) <= 3)
		sort_three(&a);
	else if (stack_size(a) <= 5)
		sort_five(&a, NULL);
	else
		//radix_sort(&a, NULL);
		turk_sort(&a, NULL);
	list_display(a, NULL);
	push_swap_exit(NULL, NULL, &a->head, NULL);
	return (0);
}
