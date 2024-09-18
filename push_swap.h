/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:55 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 12:17:50 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "stack_utils.h"
# include "algorithms_utils.h"
# include "operations.h"

typedef struct s_spec
{
	int				min;
	unsigned int	n_min;
	int				max;
	unsigned int	n_max;
	int				med;
	int				size;
	int				position;
}	t_spec;	

void	push_swap_exit(char *prt, char **args, t_stack **a, t_stack **b);
t_stack	*ps_parse(char **args);
t_stack	*ps_parse_split(char *s, char c);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack *b);
void	turk_sort(t_stack **a, t_stack *b);
void	radix_sort(t_stack **a, t_stack *b);
t_spec	fill_specs(t_stack *stk, t_stack *target);
int		min(int x, int y);
int		max(int x, int y);

void	list_display(t_stack *head_a, t_stack *head_b);
void	list_n_display(t_stack *head_a, t_stack *head_b);
void	list_r_display(t_stack *head_a, t_stack *head_b);
#endif
