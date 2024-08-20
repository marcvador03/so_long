/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:55 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/20 18:09:56 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	value;
	struct s_stack *head;
	struct s_stack *next;
}	t_stack;
void	stack_addback(t_stack **stk, void *head, int value);
void	stack_addfront(t_stack **stk, void *head, int value);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stk);
int	stack_size(t_stack *stk);
void	list_display(t_stack *stk);
void	list_full_display(t_stack *stk);

#endif

