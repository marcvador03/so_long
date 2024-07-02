/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:01:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/02 17:41:35 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_split_size(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

static int	ft_split_loop(char *s, char c, char **sub_str)
{
	int	len;
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	len = ft_strlen(s);
	*sub_str = ft_substr(s, 0, i);
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	int		len;
	char	**ptr;
	char	*str;

	cnt = ft_split_size(s, c);
	ptr = (char **)malloc((cnt + 2) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (i <= cnt)
	{
		len = ft_split_loop(str, c, &ptr[i]);
		if (ptr[i] == NULL)
			return (NULL);
		str = (str + len + 1);
		i++;
	}
	ptr[cnt + 1] = NULL;
	return (ptr);
}
