/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:13:19 by smihata           #+#    #+#             */
/*   Updated: 2023/03/08 17:00:03 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t x, size_t y)
{
	if (x > y)
		return (y);
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_len;

	s_len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (min(len, s_len) + 1));
	if (!dst)
		return (NULL);
	if (start >= s_len || len == 0)
		return (ft_memset(dst, '\0', sizeof(char)));
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
