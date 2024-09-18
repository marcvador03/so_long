/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:19:29 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/18 00:23:22 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

void	swap(t_stack **stk, char *prt);
void	push(t_stack **stk_o, t_stack **stk_i, char *prt);
void	rotate(t_stack **stk, char *prt);
void	r_rotate(t_stack **stk, char *prt);
void	double_rotate(t_stack **stk_1, t_stack **stk_2, char *prt, int rev);
#endif
