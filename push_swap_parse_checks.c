/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_checks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:40:24 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/03 13:45:47 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_params(struct s_params *p, t_stack *stk)
{
	int	cnt;
	int	i;

	cnt = stack_size(stk);
	p->min = stk->value;
	p->max = stk->value;
	stk = stk->next;
	i = 1;
	while (i++ < cnt)
	{
		if (p->min > stk->value)
			p->min = stk->value;
		if (p->max < stk->value)
			p->max = stk->value;
		stk = stk->next;
	}
}
static int	ps_duplicates(t_stack *stk)
{
	t_stack	*tmp;
	t_stack	*head;
	int	n;

	head = stk;
	while (stk->next != NULL)
	{
		tmp = stk->next;
		n = stk->value;
		while (tmp!= NULL)
		{
			if (n == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		stk = stk->next;
	}
	return (1);
}
static int	ps_sanity_check(char **args)
{
	int		i;
	int		j;
	int		n;
	char	*str;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_isdigit(args[i][0]) == 0)
			if(args[i][0] != '-' && args[i][0] != '+')
				return(0);
		j = 1;
		while (args[i][j] != '\0')
			if (ft_isdigit(args[i][j++]) == 0)
				return (0);
		n = ft_atoi(args[i]);
		str = ft_itoa(n);
		if (ft_strncmp(str, args[i], j) != 0)
			return (free(str), 0);
		free(str);
		i++;
	}
	return (1);	
}

t_stack	*ps_parse_split(char *s, char c)
{
	int		i;
	char	*str;
	char	**args;
	t_stack	*stk;

	i = 0;
	str = s;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
			str[i] = ' ';
		i++;
	}
	args = ft_split(str, c);
	if (args == NULL)
		push_swap_exit("Error\n", NULL, NULL);
	if (ps_sanity_check(args) == 0)
		push_swap_exit("Error\n", args, NULL);
	stk = ps_parse(args);
	i = 0;
	while (args[i] != NULL)
		free(args[i++]);
	return (free(args), stk);
}

t_stack	*ps_parse(char **args)
{
	t_stack	*head;
	t_stack	*a;
	int	i;

	if (ps_sanity_check(args) == 0)
		push_swap_exit("Error\n", NULL, NULL);
	a = stack_new(ft_atoi(*args), 0);
	head = a;
	a->next = NULL;
	i = 1;
	while (args[i] != NULL)
		stack_addback(&a, ft_atoi(args[i++]), 0);
	if (ps_duplicates(head) == 0)
		push_swap_exit("Error\n", args, &head);
	return (head);
}
