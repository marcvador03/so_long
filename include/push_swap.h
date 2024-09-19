/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:55 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/19 17:17:50 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_spec
{
	int				min;
	unsigned int	n_min;
	int				max;
	unsigned int	n_max;
	int				med;
	int				size;
	int				rel_pos;
}	t_spec;	

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
/*Push Swap standard operations*/
void	swap(t_stack **stk, char *prt);
void	push(t_stack **stk_o, t_stack **stk_i, char *prt);
void	rotate(t_stack **stk, char *prt);
void	r_rotate(t_stack **stk, char *prt);
void	double_rotate(t_stack **stk_1, t_stack **stk_2, char *prt, int rev);

/*Sorting functions and exit*/
void	push_swap_exit(char *prt, char **args, t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack *b);
void	turk_sort(t_stack **a, t_stack *b);

/*Input parsing and sanity checks*/
t_stack	*ps_parse(char **args, int flag);
t_stack	*ps_parse_split(char *s, char c);

/*Algorithms search functions and movement optimization*/
int		search_pos(t_stack *target, t_stack *stk);
t_stack	*search_next_big(unsigned int n, unsigned int min, t_stack *stk);
t_stack	*search_next_small(unsigned int n, unsigned int max, t_stack *stk);
t_stack	*search_value(int n, t_stack *stk);
void	minimize_single_rotation(t_stack **stk, t_stack *target, char *prt);
void	multiple_move(t_stack **a, t_stack **b, t_stack *tgt[2], char *prt);
void	define_mincost_targets(t_stack *stk, t_stack **target);
void	update_cost_min(t_stack *a, t_stack *b);
void	update_cost_max(t_stack *b, t_stack *a);

/*Stack operations functions*/
int		stack_size(t_stack *stk);
void	stack_addback(t_stack **stk, int value, int n_value);
t_stack	*stack_new(int value, int n_value, t_stack *head);
void	stack_head_update(t_stack *stk, t_stack *head);
t_stack	*stack_last(t_stack *stk);

/*Other utils*/
t_spec	fill_specs(t_stack *stk, t_stack *target);
int		min(int x, int y);
int		max(int x, int y);
#endif
