/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:27:39 by smihata           #+#    #+#             */
/*   Updated: 2023/03/07 10:26:10 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char		c;
	const char	*s;
	int			minus;
	long		acc;

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
		if (minus && -acc < INT_MIN)
			return ((int)LONG_MIN);
		if (!minus && INT_MAX < acc)
			return ((int)LONG_MAX);
		c = *s++;
	}
	if (minus)
		acc *= -1;
	return (acc);
}
/*
int	ft_atoi(const char *nptr)
{
	int		num;
	int		minus;
	size_t	i;

	num = 0;
	minus = 0;
	i = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = 1;
		++i;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + (nptr[i] - '0');
		++i;
	}
	if (minus)
		num *= -1;
	return (num);
}
*/