/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:03:33 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/26 23:33:37 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *ptr;

	ptr = (t_list *)malloc(sizeof (t_list));
	if (ptr == NULL)
		return ((void *)0);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
