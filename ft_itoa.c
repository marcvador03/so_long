/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:54:51 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/25 01:22:21 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	int	x;
	int	sign;
	unsigned int	cnt;

	x = n;
	sign = 0;
	if (n < 0)
		sign = 1;
	cnt = sign;
	while (x != 0)
	{
		x = x % 10;
		cnt++;
	}
	str = (char *)malloc((cnt + 2) * sizeof(char));
	if (str == NULL)
		return ((void *)0);
	str[cnt + 1] = '\0';
	while (cnt >= sign)
		str[cnt--] = (n % 10) + 48;
	if (sign == 1)
		str[0] = '-';
	return (str);
}

