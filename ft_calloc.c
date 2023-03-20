/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:40:02 by smihata           #+#    #+#             */
/*   Updated: 2023/03/19 16:43:06 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	if (size != 0 && number * size / size != number)
		return (NULL);
	ptr = (void *)malloc(size * number);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * number);
	return (ptr);
}
