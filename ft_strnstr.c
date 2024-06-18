/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:38:34 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/18 14:09:32 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int	j;

	if (len == 0)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && *big != '\0')
	{
		if (*little == *big)
		{
			j = 0;
			while (little[j] == big[j] && (i + j) < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)big);
			}
		}
		big++;
		i++;
	}
	return (0);
}
