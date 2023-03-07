/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:38:15 by smihata           #+#    #+#             */
/*   Updated: 2023/02/27 18:01:06 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dst <= src)
	{
		while (len)
		{
			*dst_ptr++ = *src_ptr++;
			len--;
		}
	}
	else
	{
		dst_ptr += len - 1;
		src_ptr += len - 1;
		while (len)
		{
			*dst_ptr-- = *src_ptr--;
			len--;
		}
	}
	return (dst);
}
