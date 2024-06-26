/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:05:08 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/27 00:09:37 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	*lst = ft_lstlast(*lst);
	(*lst)->next = new;
}

