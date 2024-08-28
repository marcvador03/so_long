/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:55 by mfleury           #+#    #+#             */
/*   Updated: 2024/08/28 19:43:35 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# define sa() swap(a);ft_printf("sa\n");
# define sb() swap(b);ft_printf("sb\n");
# define ss() swap(a);swap(b);ft_printf("ss\n");
# define pa() push(a, b);ft_printf("pa\n");
# define pb() push(b, a);ft_printf("pb\n");
# define ra() rotate(a);ft_printf("ra\n");
# define rb() rotate(b);ft_printf("rb\n");
# define rr() rotate(a);rotate(b);ft_printf("rr\n");
# define rra() r_rotate(a);ft_printf("rra\n");
# define rrb() r_rotate(b);ft_printf("rrb\n");
# define rrr() r_rotate(a);r_rotate(b);ft_printf("rrr\n");

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
}	t_stack;
void	stack_addback(t_stack **stk, int value);
void	stack_addfront(t_stack **stk, int value);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stk);
int	stack_size(t_stack *stk);
void	list_display(t_stack *stk);
void	list_full_display(t_stack *stk);
void	list_simple_display(t_stack *a, t_stack *b);
void	swap(t_stack **stk);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **stk);
void	r_rotate(t_stack **stk);
void	selection_sort(t_stack **a, t_stack **b);
void	min_sort(t_stack **a, t_stack **b, int args[2]);

#endif

