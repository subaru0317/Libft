/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:56:15 by smihata           #+#    #+#             */
/*   Updated: 2023/03/11 14:40:08 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*tmp;

// 	if (!lst || !(*lst) || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		(*del)((*lst)->content);
// 		free((*lst));
// 		*lst = NULL;
// 		*lst = tmp;
// 	}
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ndptr;

	if (!lst || !del)
		return ;
	ndptr = *lst;
	while (ndptr)
	{
		tmp = ndptr->next;
		ft_lstdelone(ndptr, del);
		ndptr = tmp;
	}
	*lst = NULL;
}
