/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:09:19 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/29 21:40:41 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (n == 0)
		return (0);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (ptr1 == NULL && ptr2 == NULL)
		return (0);
	if (ptr1 == NULL)
		return ((-1) * *ptr2);
	if (ptr2 == NULL)
		return (*ptr1);
	i = 0;
	while (i < (n - 1) && *ptr1 == *ptr2)
	{
		i++;
		ptr1++;
		ptr2++;
	}
	return (*ptr1 - *ptr2);
}
