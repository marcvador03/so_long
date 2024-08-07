/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:56:13 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/30 09:21:41 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*gnl_new(char *content, t_list *head, int fd)
{
	t_list	*ptr;
	int		len;

	ptr = (t_list *)malloc(sizeof (t_list));
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

static t_list	*gnl_free(t_list *lst)
{
	t_list	*tmp[2];

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

static char	*gnl_out_line(t_list **lst, int fd)
{
	t_list	*tmp;
	char	*res[2];	

	res[0] = NULL;
	tmp = *lst;
	*lst = (*lst)->bof;
	while ((*lst != NULL))
	{
		if ((*lst)->fd == fd)
		{
			res[1] = res[0];
			res[0] = gnl_strjoin(res[0], (*lst)->content);
			free(res[1]);
			if (*lst == tmp)
			{
				*lst = gnl_free(*lst);
				return (res[0]);
			}
			*lst = gnl_free(*lst);
		}
		else
			*lst = (*lst)->next;
	}
	return (res[0]);
}

static t_list	*gnl_fill_list(char *tmp, t_list *lst, int fd, ssize_t buf)
{
	char	*ptr;
	int		s;
	int		l;

	tmp[buf] = '\0';
	ptr = tmp;
	while (*ptr != '\0')
	{
		s = (int)(ptr - tmp);
		if (*ft_strchr(ptr, '\n') != '\0')
			ptr = (ft_strchr(tmp + (ptr - tmp), '\n') + 1);
		else
			ptr = (ft_strchr(tmp + (ptr - tmp), '\0'));
		l = (int)(ptr - tmp) - s - 1;
		if (lst == NULL)
			lst = gnl_new(gnl_substr(tmp, s, l), NULL, fd);
		else
		{
			lst = gnl_lst_move(lst, -1, -1);
			lst->next = gnl_new(gnl_substr(tmp, s, l), lst->bof, fd);
		}
		if (lst == NULL || (lst != lst->bof && lst->next == NULL))
			lst = gnl_free(lst);
	}
	return (lst);
}

char	*get_next_line(int fd)
{
	ssize_t			buffer;
	static t_list	*lst;
	char			*str;

	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (str == NULL || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (free(str), NULL);
	buffer = read(fd, str, BUFFER_SIZE);
	if ((buffer == 0 && lst == NULL) || buffer < 0)
		return (free(str), NULL);
	lst = gnl_lst_move(lst, -1, fd);
	if (buffer > 0)
		lst = gnl_fill_list(str, lst, fd, buffer);
	if (buffer == 0 && lst->fd == fd)
		lst->eol = TRUE;
	lst = lst->bof;
	while (lst->eol != TRUE || (lst->eol == TRUE && lst->fd != fd))
	{
		if (lst->next == NULL && buffer > 0)
			return (free(str), get_next_line(fd));
		else if (lst->next == NULL && buffer == 0)
			return (free(str), NULL);
		lst = lst->next;
	}
	return (free(str), gnl_out_line(&lst, fd));
}
