/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:45:10 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/25 00:59:12 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*temp;
	int	i;
	int	len;
	int	count;

	len = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[len] != '\0')
		if (s[len++] == c)
			count++;
	ptr = (char **)malloc((count + 2) * sizeof(char *));
	temp = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(temp, s, len);
	i = 0;
	count = 0;
	len = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == c)
		{
			ptr[count] = (char *)malloc((i + 1) * sizeof(char));
			ft_strlcpy(ptr[count], temp, i);
			len = len + ft_strlen(ptr[count]);
			free(temp);
			temp = (char *)malloc((ft_strlen(s) - len) * sizeof(char));
			ft_strlcpy(temp, ft_substr(s, len + 1 + count, ft_strlen(s)), ft_strlen(s) - len);
			count++;
			i = -1;
		}
		i++;
	}
	ptr[count] = (char *)malloc((i + 1) * sizeof(char));
	ft_strlcpy(ptr[count], temp, ft_strlen(s) - len);
	ptr[++count] = (void *)0;
	return (ptr);
}
