/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:54:51 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/26 15:17:21 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_itoa(int n)
{
	char	*str;
	int	x;
	int	temp;
	unsigned int	sign;
	unsigned int	cnt;

	x = n;
	sign = 0;
	temp = -1;
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		sign = 1;
		if (n == INT_MIN)
		{
			temp = n % (-10);
			temp = -temp;
			n = n / 10;
		}
		n = -(1) * n;
	}
	cnt = sign;
	while (x != 0)
	{
		x = x / 10;
		cnt++;
	}
	str = (char *)malloc((cnt) * sizeof(char));
	if (str == NULL)
		return ((void *)0);
	str[cnt--] = '\0';
	while (n != 0)
	{
		if (temp >= 0)
		{
			str[cnt--] = temp + 48;
			temp = -1;
		}
		str[cnt--] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

