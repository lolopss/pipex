/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:21:19 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/11 17:42:39 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*chr;
	int		i;

	chr = (char *)s;
	i = 0;
	while (chr[i])
	{
		if (chr[i] == (char)c)
			return (&chr[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}
