/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:34:00 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/29 13:14:36 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		set_len;
	int		s1_len;
	int		j;

	if (s1 == 0 || set == 0)
		return (NULL);
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
