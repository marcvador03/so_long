/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:22:13 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/16 15:02:44 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	
	i = 1;
	if (n == 0)
		return (0);
	while (i++ <= n)
	{
		*((unsigned char *)s) = c;
		s++;
	}
	return (s);
}
