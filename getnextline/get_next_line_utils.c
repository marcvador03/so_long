/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:25:12 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/29 18:28:19 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*gnl_lst_move(t_list *lst, int n, int fd)
{
	t_list	*tmp;

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				len;
	int				i;
	unsigned char	x;

	len = ft_strlen(s);
	x = (unsigned char)c;
	i = 0;
	while (i <= len)
	{
		if (s[i] == x)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[len] == '\0')
		return (&((char *)s)[len]);
	return (0);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_len;
	char			*str;
	char			*src;
	size_t			i;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		len = 0;
	if (s_len - start < len)
		len = s_len - start;
	str = (char *)malloc((len + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	src = ((char *)s + start);
	while (i <= len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		s1_len;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	return (str);
}
