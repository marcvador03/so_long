/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:40:58 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/27 15:57:25 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[len + 1] == '\0')
		return (&((char *)s)[len + 1]);
	return (0);
}
