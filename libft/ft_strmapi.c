/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:33:29 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/26 17:51:13 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;
	char	*p1;

	if (!s || !f)
		return (NULL);
	i = 0;
	p1 = (char*)s;
	if (!(p = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	while (s[i])
	{
		p[i] = f(i, p1[i]);
		i++;
	}
	return (p);
}
