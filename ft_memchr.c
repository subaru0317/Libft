/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:45:17 by smihata           #+#    #+#             */
/*   Updated: 2023/03/14 15:04:52 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*b_ptr;
	unsigned char	tmp;
	size_t			i;

	b_ptr = (unsigned char *)b;
	tmp = (unsigned char)c;
	i = 0;
	while (len)
	{
		if (b_ptr[i] == tmp)
			return ((void *)b_ptr + i);
		len--;
		i++;
	}
	return (NULL);
}
