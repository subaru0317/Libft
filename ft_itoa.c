/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:22:55 by smihata           #+#    #+#             */
/*   Updated: 2023/03/02 18:27:25 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			len;
	long long	tmp;
	int			flag;
	int			i;
	char		*str;

	len = 0;
	flag = 0;
	tmp = n;
	if (tmp == 0)
	{
		str = (char *)ft_calloc(2, sizeof(char));
		*str = '0';
		return (str);
	}
	if (tmp < 0)
	{
		len++;
		flag = 1;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (flag)
		str[i++] = '-';
	i = len;
	tmp = n;
	if (tmp < 0)
		tmp *= -1;
	while (i--)
	{
		if (flag && i == 0)
			break;
		str[i] = tmp % 10 + '0';
		tmp /= 10;	
	}
	return (str);
}