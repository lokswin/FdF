/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 04:45:57 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/30 04:54:52 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**    int fdf_keys(int key, void *param)
**    Function which allow users to control FdF with keyboard
** numbers  : keys
** 123,124 : <,>
** 38, 40  : j,k
** 32, 34  : u,i
** 126,125 : ^,v
** 78,69   : +,-
** 12, 14  : q, z
** 2 , 0   : d, a
** 13, 1   : w, s
** 49      : space
** 8       : c
** 53      : esc
** **************************************************************************
*/

static void	fdf_more_keys(int key, t_w *new_w)
{
	if (key == 126 || (key == 125 && new_w->m > 1))
		new_w->m = key == 126 ? (new_w->m + 1) : (new_w->m - 1);
	if (key == 78 || key == 69)
		new_w->mv_z = key == 78 ? new_w->mv_z - 5 : new_w->mv_z + 5;
	if (key == 12 || key == 14)
		new_w->mv_z2 = key == 12 ? new_w->mv_z2 + 10 : new_w->mv_z2 - 10;
	if (key == 2 || key == 0)
		new_w->mv_x = key == 2 ? new_w->mv_x + 10 : new_w->mv_x - 10;
	if (key == 13 || key == 1)
		new_w->mv_y = key == 13 ? new_w->mv_y - 10 : new_w->mv_y + 10;
	if (key == 49)
		fdf_initials(new_w);
	if (key == 8)
		fdf_color_change(new_w);
	if (key == 9)
	{
		new_w->color_style = (new_w->color_style + 1) % 10;
		fdf_change_color(new_w);
	}
	if (key == 53)
		exit(0);
}

int			fdf_keys(int key, void *param)
{
	t_w		*new_w;
	double	a;

	a = 5 * (M_PI / 180);
	new_w = (t_w *)param;
	if (key == 123 || key == 124)
		new_w->angle = key == 123 ? (new_w->angle + a) : (new_w->angle - a);
	if (key == 38 || key == 40)
	{
		new_w->angle_x = key == 38 ? (new_w->angle_x + a) :\
			(new_w->angle_x - a);
	}
	if (key == 32 || key == 34)
	{
		new_w->angle_y = key == 32 ? (new_w->angle_y + a) : \
			(new_w->angle_y - a);
	}
	fdf_more_keys(key, new_w);
	fdf_redraw(new_w);
	return ((int)param);
}
