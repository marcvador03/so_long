/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:20:52 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/27 17:40:22 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		s1_len;
	int		i;

	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	return (str);
}
