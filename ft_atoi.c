/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:55:54 by mfleury           #+#    #+#             */
/*   Updated: 2024/06/29 12:56:07 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>

static int	ft_atoi_lim(int *res, const char **nptr)
{
	int	sign;

	sign = 1;
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == 32)
		nptr++;
	if (**nptr == 45 || **nptr == 43)
		if (**nptr++ == 45)
			sign *= -1;
	if (**nptr != '\0' && **nptr >= 48 && **nptr <= 57)
		res = res + (**nptr++ - 48);
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	if (*nptr == '\0')
		return (0);
	res = 0;
	sign = ft_atoi_lim(&res, &nptr);
	while (*nptr != '\0' && *nptr >= 48 && *nptr <= 57)
	{
		if (res != 0)
		{
			if ((INT_MAX / 10) <= res && (INT_MAX % 10) < (*nptr - 48))
			{
				if (sign == -1)
					return (INT_MIN);
				else
					return (INT_MAX);
			}
			res *= 10;
		}
		res = res + (*nptr++ - 48);
	}
	return (res * sign);
}
