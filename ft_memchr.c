/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:56:06 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/17 21:13:47 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char *ptr;
	unsigned int x;

	i = 0;
	ptr = (unsigned char *)s;
	if (c < 0)
		return (0);
	x = (unsigned int)c;
	while (i < n)
	{
		if (*ptr == (unsigned char)x)
			return (ptr);
		ptr++;
		i++;
	}
	return (0);
}
