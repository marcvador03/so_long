/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:56:06 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/18 16:59:44 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned int	x;
	size_t			i;

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
