/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:22:55 by smihata           #+#    #+#             */
/*   Updated: 2023/03/08 16:28:04 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_zero(void)
{
	char	*str;

	str = (char *)ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	*str = '0';
	return (str);
}

static char	*ft_itoa_exe(size_t len, size_t flag, long long n_tmp)
{
	char	*str;
	size_t	i;

	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (flag)
		str[i++] = '-';
	i = len;
	if (n_tmp < 0)
		n_tmp *= -1;
	while (i--)
	{
		if (flag && i == 0)
			break ;
		str[i] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long long	n_tmp;
	size_t		flag;

	len = 0;
	flag = 0;
	n_tmp = n;
	if (n_tmp == 0)
		return (ft_itoa_zero());
	if (n_tmp < 0)
	{
		len++;
		flag = 1;
		n_tmp *= -1;
	}
	while (n_tmp > 0)
	{
		n_tmp /= 10;
		len++;
	}
	n_tmp = n;
	return (ft_itoa_exe(len, flag, n_tmp));
}
