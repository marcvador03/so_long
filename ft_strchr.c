/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:44:28 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/30 01:10:49 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

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
