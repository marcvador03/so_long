/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:01:20 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/27 00:04:18 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != ((void *)0))
		lst = lst->next;
	return (lst);
}
