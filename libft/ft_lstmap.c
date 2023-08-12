/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:15:30 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/17 16:15:30 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first;

	if (!lst || !f || !del)
		return (NULL);
	first = 0;
	while (lst)
	{
		new_list = ft_lstnew((f)(lst->content));
		if (!new_list)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new_list);
		lst = lst->next;
	}
	return (first);
}
