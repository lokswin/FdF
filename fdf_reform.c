/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/22 21:15:25 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	void fdf_rotate_xy(int *x, int *y, int z, int iso_p)
**	Function for map rotation
** **************************************************************************
*/

void		fdf_rotate_xy(double *x, double *y, double z, t_w *new_w)
{
	double	angle;
	double	tmp_x;
	double	tmp_y;

	printf("\n-------fdf_rotate_xy start-------\n");
	angle = new_w->angle;
	tmp_x = *x;
	tmp_y = *y;
	if (new_w->iso_p == 0)//Slanting right:
	{
		*x = (tmp_x + tmp_y) * cos(angle);
		*y = (tmp_x - tmp_y) * -sin(angle) - z;
	}
	else if (new_w->iso_p == 1)//Slanting left:
	{
		*x = (tmp_x - tmp_y) * -cos(angle);
		*y = ((tmp_x + tmp_y) * -sin(angle)) - z;
		new_w->x_mid = (new_w->x_mid + new_w->y_mid) * cos(angle);
		new_w->y_mid = (new_w->x_mid - new_w->y_mid) * cos(angle);
		//new_w->y_mid = new_w->y_mid * 1.125;
		//new_w->x_mid = new_w->x_mid * 1.45;
	}
	else if (new_w->iso_p == 2)//Mirror image slanting right:
	{
		*x = (tmp_x - tmp_y) * cos(angle);
		*y = ((tmp_x + tmp_y) * -sin(angle)) - z;
		new_w->x_mid = (new_w->x_mid + new_w->y_mid) * cos(angle);
		new_w->y_mid = (new_w->x_mid - new_w->y_mid) * cos(angle);
		//new_w->y_mid *= 1.125;
		//new_w->x_mid *= 1.25;
	}
	else if (new_w->iso_p == 3)//Mirror image slanting left:
	{
		*x = (tmp_x + tmp_y) * -cos(angle);
		*y = ((tmp_x - tmp_y) * -sin(angle)) - z;
		new_w->x_mid = (new_w->x_mid + new_w->y_mid) * cos(angle);
		//new_w->x_mid *= 1.6;
	}

	printf("\n-------fdf_rotate_xy end-------\n");
}

/*
** **************************************************************************
**	int fdf_redraw(t_w *new_w)
**	Function to redraw img after changes;
** **************************************************************************
*/

int			fdf_redraw(t_w *new_w)
{
	int		i;

	printf("\n-------fdf_redraw start-------\n");
	i = 0;
	mlx_clear_window(new_w->mlx_p, new_w->win_p);
	fdf_ui(new_w, 0);
	while (i < (new_w->p_nb - 1))
	{
		fdf_p_struct(new_w->point, i);
		if (new_w->point[i].y == new_w->point[i + 1].y)
			fdf_dw_ln(new_w->point, *new_w, i, i + 1);//horiz lines
	 	if (((i + new_w->mv) > 0) && ((i + new_w->mv) < new_w->p_nb))
			fdf_dw_ln(new_w->point, *new_w, i, i + new_w->mv);//vert lines
		i++;
	}
	printf("\n-------fdf_redraw end-------\n");
	return (1);
}

/*
** **************************************************************************
**	man /usr/share/man/man3/mlx.1
**	man /usr/share/man/man3/mlx_loop.1
**	man /usr/share/man/man3/mlx_new_image.1
**	man /usr/share/man/man3/mlx_new_window.1
**	man /usr/share/man/man3/mlx_pixel_put.1
** **************************************************************************
*/
