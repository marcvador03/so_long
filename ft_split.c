/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:45:10 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/20 16:29:08 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int	i;
	int	count;
	char	*temp;

	i = 0;
	temp = s;
	if (s == 0)
		return (0);
	while (ft_strrchr(s, (int)c) + 1 != 0)
		ft_split(ft_strchr(s, (int)c) + 1, c);


}
