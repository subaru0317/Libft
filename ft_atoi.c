/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:27:39 by smihata           #+#    #+#             */
/*   Updated: 2023/03/09 12:45:12 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(unsigned char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_is_overflow_or_underflow(int sign)
{
	if (sign < 0)
		return ((int)LONG_MIN);
	else
		return ((int)LONG_MAX);
}

static int	ft_atoi_exe(unsigned long cutoff, char c,
						const char *nptr, int sign)
{
	int				cutlim;
	unsigned long	acc;

	cutlim = cutoff % 10;
	cutoff /= 10;
	acc = 0;
	while ('0' <= c && c <= '9')
	{
		c -= '0';
		if (acc > cutoff || (acc == cutoff && c > cutlim))
			return (ft_is_overflow_or_underflow(sign));
		acc = acc * 10 + c;
		c = *nptr++;
	}
	return (acc * sign);
}

int	ft_atoi(const char *nptr)
{
	char			c;
	int				sign;
	unsigned long	cutoff;

	c = *nptr++;
	while (ft_isspace((unsigned char)c))
		c = *nptr++;
	if (c == '-')
	{
		sign = -1;
		c = *nptr++;
		cutoff = LONG_MIN;
	}
	else
	{
		sign = 1;
		if (c == '+')
			c = *nptr++;
		cutoff = LONG_MAX;
	}
	return (ft_atoi_exe(cutoff, c, nptr, sign));
}
