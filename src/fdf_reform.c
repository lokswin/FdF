/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/19 21:15:01 by drafe            ###   ########.fr       */
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
	static double	angle;
	double	tmp_x;
	double	tmp_y;
    double	tmp_z;
	double pi;

	tmp_z = 0;
	pi = M_PI;
	angle = new_w->angle;
	if ((z != 0))
        tmp_z = z + new_w->mv_z;
	tmp_x = *x + new_w->mv_x;
	tmp_y = *y + new_w->mv_y;
	if (new_w->iso_p == 0)//<- Slanting right:
	{
		*x = ((tmp_x + tmp_y) * cos(angle * (pi / 180)));
		*y = ((tmp_x - tmp_y) * -sin(angle * (pi / 180))) - tmp_z;
	}
	else if (new_w->iso_p == 1)//-> Slanting left:
	{
		*x = (tmp_x - tmp_y) * -cos(angle * (pi / 180));//-
		*y = ((tmp_x + tmp_y) * -sin(angle * (pi / 180))) - tmp_z;
	}
	else if (new_w->iso_p == 2)//v Mirror image slanting right:
	{
		*x = (tmp_x - tmp_y) * cos(angle * (pi / 180));
		*y = ((tmp_x + tmp_y) * -sin(angle * (pi / 180))) - tmp_z;
	}
	else if (new_w->iso_p == 3)//^ Mirror image slanting left:
	{
		*x = (tmp_x + tmp_y) * -cos(angle * (pi / 180));
		*y = ((tmp_x - tmp_y) * -sin(angle * (pi / 180))) - tmp_z;
	}
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

	i = 0;
    parts = new_w->p_nb / 500;
	mlx_clear_window(new_w->mlx_p, new_w->win_p);
	fdf_ui(new_w, 0);
    if (parts >= 2)
        fdf_speed_up(new_w);
    else
        while (i < (new_w->p_nb - 1))
        {
		    if (new_w->p[i].y == new_w->p[i + 1].y)
			    fdf_dw_ln(new_w->p, *new_w, i, i + 1);//horiz lines
	 	    if (((i + new_w->mv) > 0) && ((i + new_w->mv) < new_w->p_nb))
		    	fdf_dw_ln(new_w->p, *new_w, i, i + new_w->mv);//vert lines
		i++;
	}
	return (1);
}

/*
** **************************************************************************
**	int fdf_speed_up(t_w *new_w)
**	Function to speed_up;
** **************************************************************************
*/

void		fdf_speed_up(t_w *new_w)
{
    int		i;
    int		mv;

    mv = new_w->p_nb / 3;
    i = mv - 1;
    while (i--)
    {
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
