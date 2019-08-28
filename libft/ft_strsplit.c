/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:32:42 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/02 17:42:38 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	if (s[i] && (s[i] != c) && (s[i + 1] != c) && (s[i + 1] != 0))
		words++;
	while (s[i])
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != 0))
			words++;
		i++;
	}
	return (words);
}

static int	ft_splitstr(char **str, const char *s, char c, size_t len)
{
	size_t	count;
	size_t	lens;
	size_t	i;

	count = 0;
	i = 0;
	while (count < len)
	{
		lens = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			lens++;
			i++;
		}
		if ((str[count] = ft_strsub(&s[i - lens], 0, lens)) == NULL)
		{
			ft_fr_words(str, count);
			return (0);
		}
		count++;
	}
	str[count] = 0;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_words(s, c);
	if ((str = ((char **)ft_memalloc(sizeof(char *) * (len + 1)))) == NULL)
		return (NULL);
	if (ft_splitstr(str, s, c, len))
		return (str);
	else
		return (NULL);
	return (str);
}
