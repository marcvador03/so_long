/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:50:14 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/30 01:14:06 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	i--;
	while (i >= 0)
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i--;
	}
	return (0);
}
