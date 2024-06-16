/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:47:14 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/16 16:54:20 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	const unsigned char *str;
	
	i = 0;
	str = (unsigned char*)src;
	while (i < n)
	{
		((unsigned char *)dest)[i] = str[i];
		i++;
	}
	return (dest);
}
