/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:49:22 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/24 05:14:45 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *obj, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = -1;
	found = 1;
	if (!ft_strlen(obj))
		return ((char *)str);
	while (*(str + ++i) && i < len)
	{
		j = 0;
		if (*(str + i) == *(obj + 0))
		{
			k = i;
			found = 1;
			while (*(str + k) && *(obj + j) && j < len && k < len)
				if (*(str + k++) != *(obj + j++))
					found = 0;
			if (found && !*(obj + j))
				return ((char *)str + i);
		}
	}
	return (NULL);
}
