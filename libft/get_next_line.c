/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:44:27 by nshelly           #+#    #+#             */
/*   Updated: 2019/06/27 14:17:14 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	divide_and_conserve(int fd, char **saved, char **line)
{
	size_t	length;

	if (ft_strchr(saved[fd], '\n'))
	{
		*line = ft_strsub(saved[fd], 0, ft_strchr(saved[fd], '\n') - saved[fd]);
		length = ft_strlen(*line) + 1;
		saved[fd] = ft_strsub(saved[fd], (unsigned int)(length),
				(size_t)(ft_strlen(saved[fd]) - (length)));
	}
	else
	{
		*line = ft_strdup(saved[fd]);
		length = ft_strlen(*line);
		saved[fd] = ft_strsub(saved[fd], (unsigned int)(length),
		(size_t)(ft_strlen(saved[fd]) - (length)));
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*saved[10240];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		r;

	r = 0;
	if ((fd < 0) || (fd > 10240) || (!line) || (!saved[fd] && \
				!(saved[fd] = ft_strnew(0))))
		return (-1);
	while (!ft_strchr(saved[fd], '\n') && (r = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[r] = '\0';
		tmp = saved[fd];
		saved[fd] = ft_strjoin(saved[fd], buffer);
		ft_strdel(&tmp);
	}
	if (r == -1)
		return (-1);
	tmp = saved[fd];
	if (!(*tmp))
		return (0);
	divide_and_conserve(fd, saved, line);
	ft_strdel(&tmp);
	return (1);
}
