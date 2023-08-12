/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:32:56 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/17 13:39:55 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list1;

	list1 = (t_list *)malloc(sizeof(t_list));
	if (!list1)
		return (NULL);
	list1->content = content;
	list1->next = NULL;
	return (list1);
}
