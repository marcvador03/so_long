/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:25:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/03 17:04:07 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*gnl_lst_move(t_gnl_list *lst, int n, int fd)
{
	t_gnl_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	if (n == -1 && fd == -1)
		while (lst->next != NULL)
			lst = lst->next;
	else if (n == -1 && fd != -1)
	{
		lst = lst->bof;
		while (lst->next != NULL)
		{
			lst = lst->next;
			if (lst->fd == fd)
				tmp = lst;
		}
		lst = tmp;
	}
	return (lst);
}

t_gnl_list	*gnl_new(char *content, t_gnl_list *head, int fd)
{
	t_gnl_list	*ptr;
	int			len;

	ptr = (t_gnl_list *)malloc(sizeof (t_gnl_list));
	if (ptr == NULL)
		return (NULL);
	len = ft_strlen(content);
	ptr->eol = 0;
	if (content[len - 1] == '\n')
		ptr->eol = 1;
	ptr->content = content;
	ptr->fd = fd;
	ptr->bof = head;
	if (head == NULL)
		ptr->bof = ptr;
	ptr->next = NULL;
	return (ptr);
}

t_gnl_list	*gnl_free(t_gnl_list *lst)
{
	t_gnl_list	*tmp[2];

	if (lst == NULL)
		return (NULL);
	if (lst == lst->bof && lst->next == NULL)
		return (free(lst->content), free(lst), NULL);
	else if (lst == lst->bof && lst->next != NULL)
		tmp[1] = lst->next;
	else if (lst != lst->bof)
		tmp[1] = lst->bof;
	tmp[0] = lst;
	lst = lst->bof;
	while (lst != NULL)
	{
		lst->bof = tmp[1];
		if (lst->next == tmp[0])
			lst->next = tmp[0]->next;
		lst = lst->next;
	}
	return (free(tmp[0]->content), free(tmp[0]), tmp[1]);
}
