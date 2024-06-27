/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:13:04 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/28 01:28:24 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../Misc/Tests/inc/t_test.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	len;

	if (dst == NULL || size == 0)
		return (0);
	len = ft_strlen(dst);
	if (src == NULL)
		return (len);
	i = 0;
	while (i <= (int)(size - len - 1) && src[i] != '\0')
	{
		dst[len + i] = src[i];
		i++;
	}
	if (i + len == size)
		return (size);
	else
	{
		dst[size] = '\0';
		return (size);
	}
	return (len + i);
}
