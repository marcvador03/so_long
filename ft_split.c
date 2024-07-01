/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:01:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/01 16:14:48 by mfleury          ###   ########.fr       */
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
	return (cnt + 1);

}

static void	ft_split_loop(char *s, char c, char *sub_str)
{
	int	len;

	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	while (*s != '\0' && *s != c)
		s++;
	len = ft_strlen(s);
	sub_str = ft_substr(s, 1, len);
	ft_putstr_fd(sub_str, 1);
	ft_putchar_fd('\n', 1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	char	**ptr;
	char	*str;

	cnt = ft_split_size(s, c);
	if (!(ptr = (char **)malloc((cnt + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	str = (char *)s;
	while (i <= cnt)
	{
		ft_split_loop((char *)s, c, str);
		if (ptr[i] == NULL)
			return (NULL);
		i++;
	}
	ptr[cnt + 1] = NULL;
	return (ptr);
}
