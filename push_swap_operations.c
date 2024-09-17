/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/17 16:47:27 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stk, char *prt)
{
	t_stack	*tmp;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	tmp = (*stk)->next;
	(*stk)->next = tmp->next;
	tmp->next = *stk;
	*stk = tmp;
	(*stk)->head = tmp;
	stack_head_update(*stk, tmp);
	ft_printf("%s\n", prt);
}

void	push(t_stack **stk_o, t_stack **stk_i, char *prt)
{
	t_stack	*tmp;
	t_stack	*i;
	t_stack	*o;

	i = *stk_i;
	o = *stk_o;
	if (i == NULL)
		return ;
	tmp = i->next;
	i->next = o;
	o = i;
	i = tmp;
	if (i != NULL)
	{
		i->head = i;
		stack_head_update(i, i);
	}
	o->head = o;	
	stack_head_update(o, o);
	*stk_o = o;
	*stk_i = i;
	ft_printf("%s\n", prt);
}

void	rotate(t_stack **stk, char *prt)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_last(*stk);
	tmp->next = *stk;
	tmp2 = (*stk)->next;
	(*stk)->next = NULL;
	*stk = tmp2;
	(*stk)->head = tmp2;
	stack_head_update(*stk, tmp2);
	if (ft_strncmp(prt, "rr", 2) != 0)
		ft_printf("%s\n", prt);
}

void	r_rotate(t_stack **stk, char *prt)
{
	t_stack	*tmp;

	tmp = *stk;
	*stk = stack_last(tmp);
	(*stk)->next = tmp;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (tmp->next == *stk)
			tmp->next = NULL;
		tmp = tmp->next;
	}
	(*stk)->head = *stk;
	stack_head_update(*stk, *stk);
	if (ft_strncmp(prt, "rrr", 3) != 0)
		ft_printf("%s\n", prt);
}

void	double_rotate(t_stack **stk_1, t_stack **stk_2, char *prt)
{
	rotate(stk_1, prt);
	rotate(stk_2, prt);
	ft_printf("%s\n", prt);
}

void	double_r_rotate(t_stack **stk_1, t_stack **stk_2, char *prt)
{
	r_rotate(stk_1, prt);
	r_rotate(stk_2, prt);
	ft_printf("%s\n", prt);
}

int	search_pos(t_stack *target, t_stack *stk)
{
	int	i;

	if (target == NULL)
		return (0);
	i = 0;
	while (stk != target && stk != NULL)
	{
		i++;
		stk = stk->next;
	}
	return (i);	
}

void	minimize_rotation(t_stack **stk, t_stack *target, char *prt)
{
	t_stack	*tmp;
	t_spec	s;
	int		pos;
	int		size;

	s = fill_specs(*stk, NULL);
	tmp = *stk;
	size = stack_size(*stk);
	pos = search_pos(target, *stk);	
	if (pos > s.med)
		while (size != pos)
		{
			r_rotate(stk, prt);
			size--;
		}
	else
	{
		prt = prt + 1;
		while (pos != 0)
		{
			rotate(stk, prt);
			pos--;
		}
	}
}
