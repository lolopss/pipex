/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:53:25 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/12 13:28:14 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *str, const char *tf, size_t len)
{
	unsigned int	i;
	unsigned int	pos;

	if (!*tf)
		return ((char *)str);
	pos = 0;
	while (str[pos] && (size_t)pos < len)
	{
		if (tf[0] == str[pos])
		{
			i = 1;
			while (tf[i] != '\0' && str[pos + i] == tf[i]
				&& (size_t)(pos + i) < len)
				i++;
			if (tf[i] == '\0')
				return ((char *)str + pos);
		}
		pos++;
	}
	return (0);
}
