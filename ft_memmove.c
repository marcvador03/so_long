/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:42:28 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/30 00:55:16 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_t;
	char	*dest_t;

	src_t = (char *)src;
	dest_t = (char *)dest;
	if (dest > src && dest < (src + n))
	{
		i = n + 1;
		while (--i != 0)
			dest_t[i] = src_t[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			dest_t[i] = src_t[i];
	}
	return (dest);
}
