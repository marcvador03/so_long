/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:55 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/16 18:32:16 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	unsigned int	n_value;
	struct s_stack	*head;
	struct s_stack	*next;
}	t_stack;
struct s_params
{
	int				min;
	unsigned int	n_min;
	int				max;
	unsigned int	n_max;
	int				med;
	unsigned int	n_med;
};	
void	stack_addback(t_stack **stk, int value, int n_value);
void	stack_addfront(t_stack **stk, int value, int n_value);
t_stack	*stack_new(int value, int n_value, t_stack *head);
t_stack	*stack_last(t_stack *stk);
int		stack_size(t_stack *stk);
void	stack_head_update(t_stack **stk, t_stack **head);
void	list_simple_display(t_stack *a, t_stack *b);
void	swap(t_stack **stk, char *prt);
void	push(t_stack **a, t_stack **b, char *prt);
void	rotate(t_stack **stk, char *prt);
void	r_rotate(t_stack **stk, char *prt);
void	selection_sort(t_stack **a);
void	min_sort(t_stack **a, int min, int max);
void	radix_sort(t_stack **a, t_stack *b, unsigned int max);
void	sort_three(t_stack **a, int min, int max);
t_stack	*ps_parse(char **args);
t_stack	*ps_parse_split(char *s, char c);
void	push_swap_exit(char *prt, char **args, t_stack **stk);
void	fill_params(struct s_params *p, t_stack *stk);
void	sort_five(t_stack **a, t_stack *b);
void	insert_in_order(t_stack **a, t_stack *b, int min);
t_stack	*search_value(int n, t_stack **stk);
int		search_pos(int med, int value, t_stack *stk);

#endif
