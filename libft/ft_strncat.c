/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:57:20 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/25 04:00:18 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	ss;
	char	*s;

	ss = ft_strnlen(s2, n);
	s = s1;
	s1 += ft_strlen(s1);
	s1[ss] = '\0';
	ft_memcpy(s1, s2, ss);
	return (s);
}
