/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/19 20:53:00 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	static void fdf_mv_find(t_w *new_w, int p_nb)
**	Function to find next line point
** **************************************************************************
*/

static void			fdf_mv_find(t_w *new_w)
{
	int			tmp;
	int			i;

	tmp = 0;
	i = 0;
	while (i < (new_w->p_nb - 1))
	{
		if (new_w->p[i].x > tmp)
			tmp = new_w->p[i].x;
		i++;
	}
	new_w->mv = 1 + (tmp / new_w->map_ln);
}

/*
** **************************************************************************
**	void fdf_dw_ln(t_crds *point, t_w new_w, int p1, int p2)
**	Function to draw one line betwen p1 and p2
** **************************************************************************
*/

int			fdf_dw_ln(t_crds *all_ps, t_w new_w, int p1, int p2)
{
    double	x1;
    double	y1;
    double  x2;
    double  y2;
	double	dx;
	double	dy;
    int		step;
    double  dx2;
    double  dy2;
    double  x_n;
    double  y_n;
    double     decimal;


    max_min(&new_w);
    set_colors(&new_w);
	x2 = all_ps[p2].x;
	y2 = all_ps[p2].y;
	fdf_rotate_xy(&x2, &y2, all_ps[p2].z, &new_w);
	dx = x2;
	dy = y2;
	x1 = all_ps[p1].x;
	y1 = all_ps[p1].y;
	fdf_rotate_xy(&x1, &y1, all_ps[p1].z, &new_w);
	dx = dx - x1;
	dy = dy - y1;
    dx2 = fabs(x1 - x2);
    dy2 = fabs(y1 - y2);
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
    //x1 += new_w.x_mid;
    //y1 += new_w.y_mid;
    x_n = x1;
    y_n = y1;
	while(step--)
	{
        decimal = (dx2 > dy2) ? get_line_pnt(x1, x2, x_n) : get_line_pnt(y1, y2, y_n);
        new_w.color = color_lint(all_ps[p1].color, all_ps[p2].color, decimal);
		//printf("x1=%f, y1=%f, step=%d, dx=%f, dy=%f iso_p=%d\n", x1, y1, step, dx, dy, new_w.iso_p);
	 	mlx_pixel_put(new_w.mlx_p, new_w.win_p, x_n + new_w.x_mid, y_n + new_w.y_mid, new_w.color);//100 + x_n, 380 + y_n, new_w.color);
		x_n = x_n + dx;
    	y_n = y_n + dy;
	}
	return (1);
	
}

/*
** **************************************************************************
**	int fdf_draw(t_crds all_ps[260000], int p_nb, char *source_f)
**	Function to draw
** **************************************************************************
*/

int					fdf_draw(t_w *new_w)
{
	mlx_key_hook(new_w->win_p, fdf_keys, new_w);
	fdf_mv_find(new_w);
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

		/* i = (x1 * (new_w.bitspp / 8)) + (y1 * new_w.ln_sz);
		new_w.img[i] = new_w.color; // B — Blue
		new_w.img[++i] = new_w.color >> 8; // G — Green
		new_w.img[++i] = new_w.color >> 16; // R — Red
		new_w.img[++i] = 0;*/