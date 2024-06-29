/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:01:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/29 21:44:15 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_split_2(char **temp, int n, char *str, int *i)
{
	free(*temp);
	*temp = (char *)malloc(n * sizeof(char));
	ft_strlcpy(*temp, str, n);
	*i = -1;
}

static char	**ft_split_loop(char const *s, char c, int len, int count)
{
	char	**ptr;
	char	*temp;
	int		i;
	int		l;

	temp = (char *)malloc((len + 1) * sizeof(char));
	l = ft_strlen(s);
	ft_strlcpy(temp, s, len);
	ptr = (char **)malloc((count + 2) * sizeof(char *));
	i = -1;
	len = 0;
	count = 0;
	while (temp[++i] != '\0')
	{
		if (temp[i] == c)
		{
			ptr[count] = (char *)malloc((i + 1) * sizeof(char));
			len = len + (int)ft_strlcpy(ptr[count], temp, i);
			ft_split_2(&temp, l - len, ft_substr(s, len + 1 + count++, l), &i);
		}
	}
	ptr[count] = (char *)malloc((i + 1) * sizeof(char));
	ft_strlcpy(ptr[count], temp, l - len);
	ptr[++count] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		len;
	int		count;

	len = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[len] != '\0')
		if (s[len++] == c)
			count++;
	ptr = ft_split_loop(s, c, len, count);
	return (ptr);
}
