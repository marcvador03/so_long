/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:40:24 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/02 23:56:31 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sanity_check(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL)
	{
		while ()
	}


}
t_stack	ps_parse(char **args)
{
	t_stack	*head;
	t_stack	*a;
	int	i;

	a = stack_new(ft_atoi(*args), 0);
	head = a;
	a->next = NULL;
	i = 0;
	while (args[i] != NULL)
		stack_addback(&a, ft_atoi(args[i++]), 0);
	return (*head);
}
