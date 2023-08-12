/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:59:05 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/17 16:59:10 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (alst != NULL && *alst != NULL)
	{
		elem = *alst;
		elem = ft_lstlast(*alst);
		elem->next = new;
		return ;
	}
	*alst = new;
}
