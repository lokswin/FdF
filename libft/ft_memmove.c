/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:23:03 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/11 05:19:50 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*cd;
	const char	*cs;

	d = dst;
	s = src;
	cd = d + (len - 1);
	cs = s + (len - 1);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		while (len--)
			*cd-- = *cs--;
	}
	return (dst);
}
