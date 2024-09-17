/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/17 16:48:59 by mfleury          ###   ########.fr       */
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

t_spec	fill_specs(t_stack *stk, t_stack *target)
{
	t_spec	s;

	s.size = stack_size(stk);
	s.position = search_pos(target, stk); 
	stk = stk->head;
	while (stk != NULL)
	{
		if (s.min > stk->value || stk == stk->head)
		{
			s.min = stk->value;
			s.n_min = stk->n_value;
		}
		if (s.max < stk->value || stk == stk->head)
		{
			s.max = stk->value;
			s.n_max = stk->n_value;
		}
		stk = stk->next;
	}
	s.med = s.size / 2;
	return (s);
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
		turk_sort(&a, b);
	list_simple_display(a->head, NULL);
	push_swap_exit(NULL, NULL, &a->head);
	return (0);
}
