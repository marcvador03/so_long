/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:47:07 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/29 21:47:51 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;

	if (dst == NULL)
		return (0);
	dst_l = ft_strlen(dst);
	if (src == NULL)
		return (dst_l);
	i = dst_l;
	while (src[i - dst_l] != '\0' && i < size)
	{
		dst[i] = src[i - dst_l];
		i++;
	}
	dst[i] = '\0';
	if (i < size)
		return (i);
	return (size);
}
