/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 05:10:03 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/30 05:46:21 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**    int file_to_arr(char *s, int i)
**    Function to store coords
**    while //printf("buff[%d]=%s, tmp_z[%d]= %d", x, buff[x], x, tmp_z[x]);
** **************************************************************************
*/

void		file_to_arr(t_w *new_w, char *s, int y)
{
	char	**buff_splt;
	int		i;
	int		x;

	i = 0;
	x = 0;
	buff_splt = ft_strsplit(s, ' ');
	while (buff_splt[x] != '\0')
		x++;
	while (i < x)
	{
		new_w->p[new_w->p_nb].x = new_w->map_ln * i;
		new_w->p[new_w->p_nb].y = new_w->map_ln * y;
		new_w->p[new_w->p_nb].z = new_w->map_ln * ft_atoi(buff_splt[i]);
		new_w->p_nb++;
		i++;
	}
}

int				count_points(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] > 32) && (s[i + 1] <= 32))
			count++;
		i++;
	}
	return (count);
}
