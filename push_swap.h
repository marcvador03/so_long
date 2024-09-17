/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:55 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/17 13:02:55 by mfleury          ###   ########.fr       */
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
	unsigned int	r_value;
	struct s_stack	*head;
	struct s_stack	*next;
}	t_stack;

typedef struct s_spec
{
	int				min;
	unsigned int	n_min;
	int				max;
	unsigned int	n_max;
	int				med;
}	t_spec;	
void	stack_addback(t_stack **stk, int value, int n_value);
void	stack_addfront(t_stack **stk, int value, int n_value);
t_stack	*stack_new(int value, int n_value, t_stack *head);
t_stack	*stack_last(t_stack *stk);
int		stack_size(t_stack *stk);
void	stack_head_update(t_stack *stk, t_stack *head);
void	list_simple_display(t_stack *a, t_stack *b);
void	swap(t_stack **stk, char *prt);
void	push(t_stack **a, t_stack **b, char *prt);
void	rotate(t_stack **stk, char *prt);
void	r_rotate(t_stack **stk, char *prt);
void	selection_sort(t_stack **a);
void	min_sort(t_stack **a, int min, int max);
void	radix_sort(t_stack **a, t_stack *b);
void	sort_three(t_stack **a);
t_stack	*ps_parse(char **args);
t_stack	*ps_parse_split(char *s, char c);
void	push_swap_exit(char *prt, char **args, t_stack **stk);
t_spec	fill_specs(t_stack *stk);
void	sort_five(t_stack **a, t_stack *b);
void	insert_in_order(t_stack **a, t_stack *b, unsigned int min);
t_stack	*search_value(int n, t_stack *stk);
t_stack	*search_n_value(unsigned int n, t_stack *stk);
void	minimize_rotation(t_stack **stk, t_stack *target, char *prt);
t_stack	*search_next_big(unsigned int n, unsigned int min, t_stack *stk);

#endif
