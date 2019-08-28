/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:17:25 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/26 18:30:26 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strnlen(const char *str, size_t maxlen)
{
	char	*p;

	p = ft_memchr(str, 0, maxlen);
	if (p == NULL)
		return (maxlen);
	else
		return (p - str);
}
