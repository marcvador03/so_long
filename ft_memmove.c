/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:47:14 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/17 14:50:01 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_t;
	char	*dest_t;

	src_t = (char *)src;
	dest_t = (char *)dest;
	if (dest > src && dest < (src + n))
	{
		//ft_putchar('#');
		i = n;
		while (i != 0)
		{
			dest_t[i] = src_t[i];
			i--;
		}
	}
	else
	{
		//ft_putchar('@');
		i = 0;
		while (i < n)
		{
			dest_t[i]  = src_t[i];
			i++;
		}
	}
	return (dest);
}
