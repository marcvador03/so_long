/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:34:00 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/20 15:41:54 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	i;
	int	set_len;
	int	s1_len;
	int	j;

	if (s1 == 0 || set == 0)
		return (void *)0;
	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1);
	if (set_len > s1_len)
		return (void *)0;
	j =  0;
	i = 0;
	while (i < set_len && set[i] == s1[s1_len - set_len + i])
		if(++i == set_len)
			s1_len = s1_len - i;
	i = 0;
	while (i < set_len && set[i] == s1[i])
		if(++i == set_len)
			j = i;
	/*str = (char *)malloc((s1_len - j + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	//str = (char *)s1;*/
	str = ft_substr(s1, j, s1_len - j);
	return (str);
}
