/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/16 13:31:22 by mfleury          ###   ########.fr       */
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

static void	stk_sorted(t_stack **a)
{
	t_stack	*head;
	int		prev;

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
			return ;
		}
	}
	push_swap_exit(NULL, NULL, &head);
}

static void	normalize_neg(t_stack *a, struct s_params *p)
{
	while (a != NULL)
	{
		if (p->min < 0)
			a->n_value = a->value - p->min;
		else
			a->n_value = a->value;
		a = a->next;
	}
	p->n_min = p->min;
	p->n_max = p->max;
	if (p->min < 0)
	{
		p->n_max = p->max - p->min;
		p->n_min = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct s_params	p;
	t_stack			*a;
	t_stack			*b;
	t_stack			*head_a;

	if (argc <= 1)
		exit (0);
	if (argc == 2)
		a = ps_parse_split(argv[1], ' ');
	else
		a = ps_parse(argv + 1);
	head_a = a;
	b = NULL;
	stk_sorted(&head_a);
	fill_params(&p, head_a);
	normalize_neg(head_a, &p);
//	selection_sort(&head_a);
//	min_sort(&head_a, min, max);
	if (stack_size(head_a) == 3)
		sort_three(&head_a, p.min, p.max);
	else if (stack_size(head_a) == 5)
		sort_five(&head_a, b);
	else
		radix_sort(&head_a, b, p.n_max);
	list_simple_display(head_a, NULL);	
	push_swap_exit(NULL, NULL, &head_a);
	return (0);
}
