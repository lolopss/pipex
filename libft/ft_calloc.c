/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:00:24 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/12 16:29:09 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*oui;

	if (count == (size_t)-1 || size == (size_t)-1)
		return (NULL);
	oui = malloc(count * size);
	if (!oui)
		return (NULL);
	ft_bzero(oui, count * size);
	return (oui);
}
/*
int	main(void)
{
	void	*oui = ft_calloc(1896153, 5625);
	void	*non = calloc(1896153, 5625);

	printf("%p\n", oui);
	printf("%p\n", non);
	free(oui);
	free(non);
	return(0);
}*/
