/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:48:31 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/19 17:22:37 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib_ft.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	unsigned int	i;
	
	if (len == 0)
		return (0);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = start;
	while (i < (start + (unsigned int)len) && *s != '\0')
	{
		ptr[i - start] = s[i];
		i++;
	}
	return (str)
}
