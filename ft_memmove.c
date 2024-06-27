/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:47:14 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/28 01:27:43 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_t;
	char	*dest_t;

	if (dest == NULL || src == NULL)
		return (0);
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
