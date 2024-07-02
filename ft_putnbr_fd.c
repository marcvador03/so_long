/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:30:28 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/02 16:04:46 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	x;

	x = -1;
	if (n < 0)
	{
		write (fd, "-", 1);
		if (n == INT_MIN)
		{
			x = (-1) * (n % (-10)) + 48;
			n = n / 10;
		}
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + 48;
		write (fd, &c, 1);
	}
	else
	{
		c = n + 48;
		write (fd, &c, 1);
	}
	if (x >= 0)
		write (fd, &x, 1);
}
