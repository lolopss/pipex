/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:12:10 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/11 15:17:58 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == s)
		return (dest);
	if (d < s)
		while (n--)
			*(d++) = *(s++);
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*(d--) = *(s--);
	}
	return (dest);
}
