/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:19:52 by smihata           #+#    #+#             */
/*   Updated: 2023/03/08 16:32:08 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_fd(int n, int fd)
{
	long long	n_tmp;
	char		c[20];
	size_t		len;

	n_tmp = n;
	if (n_tmp == 0)
		ft_putchar_fd('0', fd);
	if (n_tmp < 0)
	{
		n_tmp *= -1;
		ft_putchar_fd('-', fd);
	}
	len = 0;
	while (n_tmp)
	{
		c[len++] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	while (len--)
		ft_putchar_fd(c[len], fd);
}
