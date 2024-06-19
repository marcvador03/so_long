/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:34:00 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/19 18:55:10 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib_ft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	i;
	int	set_len;
	int	s1_len;

	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1);
	if (*s1 == '\0' || set_len > s1_len)
		return (0);
	str = (char)malloc(s1_len * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < set_len && set[i] == *s1++)
		if  (++i == set_len)
			str = s1;	
	s1_len -= i;
	while (i < set_len && set[i] == str[s1_len + i])
		if  (++i == set_len)
			str[s1_len] = '\0';	
	return (str);
}
