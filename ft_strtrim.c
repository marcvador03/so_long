/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:50:41 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/30 14:44:27 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		set_len;
	int		s1_len;
	int		j;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0');





	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1);
	if (set_len > s1_len)
		return (NULL);
	j = 0;
	i = 0;
	while (i < set_len && set[i] == s1[s1_len - set_len + i])
		if (++i == set_len)
			s1_len = s1_len - i;
	i = 0;
	while (i < set_len && set[i] == s1[i])
		if (++i == set_len)
			j = i;
	str = ft_substr(s1, j, s1_len - j);
	return (str);
}
