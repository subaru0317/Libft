/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:03:14 by smihata           #+#    #+#             */
/*   Updated: 2023/03/07 16:48:42 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search_chr(char const s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	front;
	size_t	back;
	char	*dst;

	if (*set == '\0')
	{
		dst = ft_strdup(s1);
		return (dst);
	}
	if (*s1 == '\0')
	{
		dst = ft_calloc(1, sizeof(char));
		return (dst);
	}
	i = 0;
	front = 0;
	back = 0;
	while (search_chr(s1[i++], set))
		front++;
	i = ft_strlen(s1) - 1;
	while (search_chr(s1[i--], set))
		back++;
	len = ft_strlen(s1) - front - back + 1;
	dst = ft_substr(s1, front, len - 1);
	dst[len - 1] = '\0';
	return (dst);
}


// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*dst;
// 	char	*dst_ptr;
// 	int		i;
// 	int		cnt;

// 	i = 0;
// 	cnt = 0;
// 	while (s1[i])
// 	{
// 		if (!search_chr(s1[i], set))
// 			cnt++;
// 		i++;
// 	}
// 	dst = (char *)malloc(sizeof(char) * (cnt + 1));
// 	if (!dst)
// 		return (NULL);
// 	dst_ptr = dst;
// 	while (*s1)
// 	{
// 		if (!search_chr(*s1, set))
// 		{
// 			*dst_ptr = *s1;
// 			dst_ptr++;
// 		}
// 		s1++;
// 	}
// 	return (dst);
// }
