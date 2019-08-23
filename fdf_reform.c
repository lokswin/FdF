/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/23 21:29:44 by drafe            ###   ########.fr       */
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

	printf("\n-------fdf_rotate_xy start--iso_p=%d--\n", new_w->iso_p);
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
	int		parts;
	int		i;

	printf("\n-------fdf_redraw start-------\n");
	i = 0;
	parts = new_w->p_nb / 500;
	mlx_clear_window(new_w->mlx_p, new_w->win_p);
	fdf_ui(new_w, 0);
	if (parts >= 2)
		fdf_speed_up(new_w, parts);
	else
		while (i < (new_w->p_nb - 1))
		{
			fdf_p_struct(new_w->p, i);
			if (new_w->p[i].y == new_w->p[i + 1].y)
				fdf_dw_ln(new_w->p, *new_w, i, i + 1);
			if (((i + new_w->mv) > 0) && ((i + new_w->mv) < new_w->p_nb))
				fdf_dw_ln(new_w->p, *new_w, i, i + new_w->mv);
			i++;
		}
	printf("\n-------fdf_redraw end-------\n");
	return (1);
}

/*
** **************************************************************************
**	int fdf_speed_up(t_w *new_w)
**	Function to speed_up;
** **************************************************************************
*/

void		fdf_speed_up(t_w *new_w, int parts)
{
	int		i;
	int		mv;

	parts += 0;
	mv = new_w->p_nb / 3;
	i = mv - 1;
	while (i--)
	{
		fdf_p_struct(new_w->p, i);
		if (new_w->p[i].y == new_w->p[i + 1].y)
			fdf_dw_ln(new_w->p, *new_w, i, i + 1);
		if (((i + new_w->mv) > 0) && ((i + new_w->mv) < new_w->p_nb))
			fdf_dw_ln(new_w->p, *new_w, i, i + new_w->mv);
		if (new_w->p[i + mv].y == new_w->p[i + 1 + mv].y)
			fdf_dw_ln(new_w->p, *new_w, i + mv, i + 1 + mv);
		if (((i + new_w->mv + mv) > 0) && ((i + new_w->mv + mv) < new_w->p_nb))
			fdf_dw_ln(new_w->p, *new_w, i + mv, i + new_w->mv + mv);
		if (new_w->p[i + (2 * mv)].y == new_w->p[i + 1 + (2 * mv)].y)
			fdf_dw_ln(new_w->p, *new_w, i + (2 * mv), i + 1 + (2 * mv));
		if (((i + new_w->mv + (2 * mv)) > 0) && \
		((i + new_w->mv + (2 * mv)) < new_w->p_nb))
			fdf_dw_ln(new_w->p, *new_w, i + (2 * mv), \
			i + new_w->mv + (2 * mv));
	}
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
