/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:27:39 by smihata           #+#    #+#             */
/*   Updated: 2023/03/08 16:17:24 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char		c;
	const char	*s;
	int			minus;
	long long	acc;

	s = nptr;
	c = *s++;
	while (ft_isspace((unsigned char)c))
		c = *s++;
	if (c == '-')
	{
		minus = 1;
		c = *s++;
	}
	else
	{
		minus = 0;
		if (c == '+')
			c = *s++;
	}
	acc = 0;
	while (1)
	{
		if ('0' <= c && c <= '9')
			c -= '0';
		else
			break ;
		acc *= 10;
		acc += c;
		c = *s++;
	}
	if (minus)
		acc *= -1;
	// if (acc > LONG_MAX)
	// 	return (LONG_MAX);
	// if (acc < LONG_MIN)
	// 	return (LONG_MIN);
	return (acc);
}

/*
Compute the cutoff value between legal numbers and illegal
numbers.  That is the largest legal value, divided by the
base.  An input number that is greater than this value, if
followed by a legal input character, is too big.  One that
is equal to this value may be valid or not; the limit
between valid and invalid numbers is then based on the last
digit.  For instance, if the range for longs is
[-2147483648..2147483647] and the input base is 10,
cutoff will be set to 214748364 and cutlim to either
7 (neg==0) or 8 (neg==1), meaning that if we have accumulated
a value > 214748364, or equal but the next digit is > 7 (or 8),
the number is too big, and we will return a range error.

Set 'any' if any `digits' consumed; make it negative to indicate
overflow.
 */