/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:50:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 22:31:06 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

typedef struct s_stack
{
	int				value;
	unsigned int	n_value;
	unsigned int	r_value;
	unsigned int	cost;
	struct s_stack	*target;
	struct s_stack	*head;
	struct s_stack	*next;
}	t_stack;

int		stack_size(t_stack *stk);
void	stack_addback(t_stack **stk, int value, int n_value);
t_stack	*stack_new(int value, int n_value, t_stack *head);
void	stack_head_update(t_stack *stk, t_stack *head);
t_stack	*stack_last(t_stack *stk);
#endif
