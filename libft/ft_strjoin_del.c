/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:40:26 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/08/30 05:32:40 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_del(char const *s1, char const *s2, int nb)
{
	char *result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		if (nb == 1 || nb == 3)
			free((char *)s1);
		if (nb == 2 || nb == 3)
			free((char *)s2);
	}
	return (result);
}

/*
** Return a new string resulting of the concatenation of the two string. If it
** succed it also free:
** (1)---the first string ,
** (2)---the second string ,
** (3)---both  or
** none (0).
*/
