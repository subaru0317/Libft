/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:38:15 by smihata           #+#    #+#             */
/*   Updated: 2023/03/14 16:14:40 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst <= src)
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	else
	{
		dst_ptr += len - 1;
		src_ptr += len - 1;
		while (len--)
			*dst_ptr-- = *src_ptr--;
	}
	return (dst);
}
