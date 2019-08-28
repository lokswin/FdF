/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:48:04 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/26 14:54:35 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t	n;
	size_t	m;
	size_t	l;
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	n = ft_pfch(s);
	m = ft_plch(s);
	if (n >= m)
		return (ft_strnew(0));
	if (!(p = ft_strnew(m - n + 1)))
		return (NULL);
	l = m - n;
	i = 0;
	while (i <= l)
	{
		p[i] = s[n];
		i++;
		n++;
	}
	p[i] = '\0';
	return (p);
}
