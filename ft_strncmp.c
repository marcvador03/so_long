/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/29 21:49:23 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (t1 == NULL && t2 == NULL)
		return (0);
	if (t1 == NULL)
		return (-*t2);
	if (t2 == NULL)
		return (*t1);
	if (n == 0)
		return (0);
	i = 0;
	while (*t1 == *t2 && *t1 != '\0' && *t2 != '\0' && i < (n - 1))
	{
		t1++;
		t2++;
		i++;
	}
	return (*t1 - *t2);
}
