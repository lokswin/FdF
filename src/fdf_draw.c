/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/30 04:43:26 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	void fdf_dw_ln(t_crds *point, t_w new_w, int p1, int p2)
**	Function to draw one line betwen p1 and p2
** **************************************************************************
*/

static void	set_dw_ln(t_w *new_w, t_draw *d, int p1, int p2)
{
	d->x2 = new_w->p[p2].x;
	d->y2 = new_w->p[p2].y;
	fdf_rotate_xy(&d->x2, &d->y2, new_w->p[p2].z, new_w);
	d->dx = d->x2;
	d->dy = d->y2;
	d->x1 = new_w->p[p1].x;
	d->y1 = new_w->p[p1].y;
	fdf_rotate_xy(&d->x1, &d->y1, new_w->p[p1].z, new_w);
	d->dx = d->dx - d->x1;
	d->dy = d->dy - d->y1;
	d->dx2 = fabs(d->x1 - d->x2);
	d->dy2 = fabs(d->y1 - d->y2);
	if (fabs(d->dx) >= fabs(d->dy))
		d->step = fabs(d->dx);
	else
		d->step = fabs(d->dy);
	d->dx = d->dx / d->step;
	d->dy = d->dy / d->step;
	d->x_n = d->x1;
	d->y_n = d->y1;
}

int			fdf_dw_ln(t_w *new_w, int p1, int p2)
{
	t_draw	d;

	max_min(new_w);
	set_colors(new_w);
	set_dw_ln(new_w, &d, p1, p2);
	while (d.step--)
	{
		d.decimal = (d.dx2 > d.dy2) ? get_line_pnt(d.x1, d.x2, d.x_n) :\
					get_line_pnt(d.y1, d.y2, d.y_n);
		new_w->color = color_lint(new_w->p[p1].color,\
				new_w->p[p2].color, d.decimal);
		mlx_pixel_put(new_w->mlx_p, new_w->win_p, d.x_n + \
				new_w->x_mid, d.y_n + new_w->y_mid, new_w->color);
		d.x_n = d.x_n + d.dx;
		d.y_n = d.y_n + d.dy;
	}
	return (1);
}

/*
** **************************************************************************
**	int fdf_draw(t_crds all_ps[260000], int p_nb, char *source_f)
**	Function to draw
** **************************************************************************
*/

int			fdf_draw(t_w *new_w)
{
	mlx_hook(new_w->win_p, 2, 0, fdf_keys, new_w);
	fdf_redraw(new_w);
	mlx_loop(new_w->mlx_p);
	return (0);
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
