/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:44:28 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/04 13:02:56 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;
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
	if (s[len + 1] == '\0')
		return (&((char *)s)[len + 1]);
	return (0);
}
