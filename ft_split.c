/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:30:39 by smihata           #+#    #+#             */
/*   Updated: 2023/03/02 17:56:00 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_substr_size(char const *s, char c)
{
	int	i;;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	cnt_substr(char const *s, char c)
{
	int		cnt;
	char	*ptr;

	cnt = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		while (*ptr == c && *ptr != '\0')
			ptr++;
		ptr += cnt_substr_size(ptr, c);
		cnt++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int		num_substr;
	int		i;
	int		j;
	int		substr_size;
	char	**arr;
	
	num_substr = cnt_substr(s, c);
	i = 0;
	j = 0;
	arr = (char **)ft_calloc(num_substr + 1, sizeof(char*));
	while (num_substr--)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		substr_size = cnt_substr_size(s + i, c);
		arr[j] = ft_substr(s, i, substr_size);
		i += substr_size;
		j++;
	}
	return (arr);
}
