/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:30:12 by smihata           #+#    #+#             */
/*   Updated: 2023/03/08 11:41:52 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
	while (len--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
