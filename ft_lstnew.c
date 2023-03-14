/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:49:06 by smihata           #+#    #+#             */
/*   Updated: 2023/03/09 13:10:51 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*acc;

	acc = malloc(sizeof(t_list));
	if (!acc)
		return (NULL);
	acc->content = content;
	acc->next = NULL;
	return (acc);
}