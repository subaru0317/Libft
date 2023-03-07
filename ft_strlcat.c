/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:32:26 by smihata           #+#    #+#             */
/*   Updated: 2023/03/02 15:56:09 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t min(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	ft_strlcpy(dst + i, src, dstsize - i);
	return (min(dstsize, dst_len) + src_len);
}
