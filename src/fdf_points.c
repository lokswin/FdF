/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 05:10:03 by nshelly           #+#    #+#             */
/*   Updated: 2019/09/01 17:26:05 by nshelly          ###   ########.fr       */
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

void	file_to_arr(t_w *new_w, char *s, int y)
{
	char	**buff_splt;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\t')
			s[i] = ' ';
		i++;
	}
	i = 0;
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
	ft_clean_map(buff_splt);
}

int		count_points(char *s)
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

void	fdf_console_man(void)
{
	ft_putstr("\n\t*** FdF by nshelly & drafe ***\n\n Man:\n\
	\t^ v     : Zoom\n\t\t< >     : Rotation arount Z-axis\n\t\tu i\
	: Rotation arount Y-axis\n\t\tj k     : Rotation arount \
	X-axis\n\t\tA D    \t: Move X-axis\n\t\tW S    \t: Move \
	Y-axis\n\t\tQ E    \t: Move Z-axis\n\t\t+ -     : Altitude\n\
	\tc v     : Change color\n\t\tESC     : Quit\n\t\tSPACE   : Reset\n");
}

void	fdf_gnl(t_read *r, t_w *new_w)
{
	if ((r->gnl_res = get_next_line(r->fd, &r->buff)) && (r->gnl_res == -1))
	{
		ft_putstr_fd("GNL read error", 2);
		ft_strdel(&r->buff);
		exit(1);
	}
	if ((r->count == -1) && (new_w->file_w == -1))
	{
		r->count = count_points(r->buff);
		new_w->file_w = ft_strlen(r->buff);
		fdf_ln_sz(new_w);
	}
	else if (r->buff && (r->count != count_points(r->buff)))
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		exit(1);
	}
}
