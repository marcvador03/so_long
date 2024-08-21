/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:55 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/22 00:07:14 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# define sa() swap(&head_a);ft_printf("sa\n");
# define sb() swap(&head_b);ft_printf("sb\n");
# define ss() swap(&head_a);swap(&head_b);ft_printf("ss\n");
# define pa() push(&head_a, head_b);ft_printf("pa\n");
# define pb() push(&head_b, head_a);ft_printf("pb\n");
# define ra() rotate(&head_a);ft_printf("ra\n");
# define rb() rotate(&head_b);ft_printf("rb\n");
# define rr() rotate(&head_a);rotate(&head_b);ft_printf("rr\n");
# define rra() r_rotate(&head_a);ft_printf("rra\n");
# define rrb() r_rotate(&head_b);ft_printf("rrb\n");
# define rrr() r_rotate(&head_a);r_rotate(&head_b);ft_printf("rrr\n");

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
}	t_stack;
void	stack_addback(t_stack **stk, int value);
void	stack_addfront(t_stack **head, int value);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stk);
int	stack_size(t_stack *stk);
void	list_display(t_stack *stk);
void	list_full_display(t_stack *head);
void	list_simple_display(t_stack *head_a, t_stack *head_b);
void	swap(t_stack **head);
void	push(t_stack **head_a, t_stack *head_b);
void	rotate(t_stack **head);
void	r_rotate(t_stack **head);

#endif

