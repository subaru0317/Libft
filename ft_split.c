/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:30:39 by smihata           #+#    #+#             */
/*   Updated: 2023/03/08 16:41:56 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_substr_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static size_t	cnt_substr(char const *s, char c)
{
	size_t	cnt;
	char	*ptr;

	cnt = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		while (*ptr == c)
			ptr++;
		if (*ptr == '\0')
			break ;
		ptr += cnt_substr_size(ptr, c);
		cnt++;
	}
	return (cnt);
}

char	**ft_split_exe(char const *s, char c, char **arr, size_t num_substr)
{
	size_t	i;
	size_t	j;
	size_t	substr_size;

	i = 0;
	j = 0;
	while (num_substr--)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		substr_size = cnt_substr_size(s + i, c);
		arr[j] = ft_substr(s, i, substr_size);
		if (!arr[j])
		{
			free(arr);
			return (NULL);
		}
		i += substr_size;
		j++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_substr;
	char	**arr;

	num_substr = cnt_substr(s, c);
	arr = (char **)ft_calloc(num_substr + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_split_exe(s, c, arr, num_substr));
}
