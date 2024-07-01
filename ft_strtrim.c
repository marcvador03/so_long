/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:50:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/01 12:37:52 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	int		j;
	int		x;

	if (s1 == NULL || set == NULL)
		return (NULL);
	//str = (char *)s1;
	x = 0;
	while (*s1 != '\0' && x == 0)
	{
		j = 0;
		while (set[j] != *s1 && x == 0)
			if (set[++j] == '\0')
				x = 1;
		if (x == 0)
			s1++;
	}
	x = 0;
	len = ft_strlen(s1);
	while (len > 0 && x == 0)
	{
		j = 0;
		while (set[j] != s1[len - 1] && x == 0)
			if (set[++j] == '\0')
				x = 1;
		if (x == 0)
			len--;
	}
	str = ft_substr(s1, 0, len);
	if (str == NULL)
		return (NULL) ;
	return (str);
}
