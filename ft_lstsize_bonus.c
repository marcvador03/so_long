/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:57:52 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/02 17:12:37 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;
	t_list	*tmp;

	cnt = 0;
	tmp = lst;
	while (tmp->next != (void *)0)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

