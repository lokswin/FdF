/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:41:36 by nshelly           #+#    #+#             */
/*   Updated: 2019/04/26 18:33:09 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pfch(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (is_wspace(s[i]) && s[i] != '\0')
		i++;
	return (i);
}