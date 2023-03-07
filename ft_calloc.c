/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:40:02 by smihata           #+#    #+#             */
/*   Updated: 2023/03/07 12:15:56 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * number);
	if (!ptr)
		return (NULL);
	if (size != 0 && number * size / size != number)
		return (NULL);
	ft_bzero(ptr, size * number);
	return (ptr);
}
