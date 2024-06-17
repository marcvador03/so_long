/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:13:04 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/17 16:26:27 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	while (i < (size - j) && src[i] != '\0')
	{
		dst[j + i] = src[i];
		i++;
	}
	if (i + j == size && src[i] != '\0')
	{
		return (size);
	}
	else
		dst[j + i] = '\0';
	return (j + i);
}
