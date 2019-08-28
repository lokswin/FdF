/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:40:34 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/26 18:33:31 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_plch(char const *s)
{
	size_t i;
	size_t m;

	if (!s)
		return (0);
	i = 0;
	m = 0;
	while (s[i] != '\0')
	{
		if (!is_wspace(s[i]))
			m = i;
		if (!is_wspace(s[i]) && is_wspace(s[i + 1]))
			m = i;
		i++;
	}
	return (m);
}
