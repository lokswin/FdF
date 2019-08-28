/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:25:37 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/25 00:29:39 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (p == 0)
		return (NULL);
	p = ft_strcpy(p, s1);
	p = ft_strcat(p, s2);
	return (p);
}
