/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:00:53 by smihata           #+#    #+#             */
/*   Updated: 2023/03/07 14:29:30 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t 	little_len;

	little_len = ft_strlen(little);
	if (!big || len < little_len)
		return (NULL);
	big_index = 0;
	if (*little) {
		while (ft_strncmp(big + big_index, little, little_len))
		{
			big_index++;
			len--;
			while (big[big_index] != *little)
			{
				if (big[big_index] == '\0' || len < 1)
					return (NULL);
				big_index++;
				len--;
			}
			if (len < little_len)
				return (NULL);
		}
	}
	return ((char *)(big + big_index));
}
