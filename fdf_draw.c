/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/23 18:41:32 by drafe            ###   ########.fr       */
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

	printf("-------fdf_find start-------\n");
	tmp = 0;
	i = 0;
	while (i < (new_w->p_nb - 1))
	{
		if (new_w->point[i].x > tmp)
			tmp = new_w->point[i].x;
		i++;
	}
	new_w->mv = 1 + (tmp / new_w->map_ln);
	printf("-------fdf_find end-------\n");
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
	double	dx;
	double	dy;
	int		step;

	printf("\n-------fdf_dw_ln start--p1=%d; p2=%d\n", p1, p2);
	x1 = all_ps[p2].x;
	y1 = all_ps[p2].y;
	fdf_rotate_xy(&x1, &y1, all_ps[p2].z, &new_w);
	dx = x1;
	dy = y1;
	x1 = all_ps[p1].x;
	y1 = all_ps[p1].y;
	fdf_rotate_xy(&x1, &y1, all_ps[p1].z, &new_w);
	dx = dx - x1;
	dy = dy - y1;
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x1 += new_w.x_mid;
	y1 += new_w.y_mid;
	while(step--)
	{
		//printf("x1=%f, y1=%f, step=%d, dx=%f, dy=%f iso_p=%d\n", x1, y1, step, dx, dy, new_w.iso_p);
	 	mlx_pixel_put(new_w.mlx_p, new_w.win_p, x1, y1, 0xFFFFFF);
		x1 = x1 + dx;
    	y1 = y1 + dy;
	}
	printf("-------fdf_dw_ln end-------width%d height%d xm%d ym%d iso =%d \
	file_w%d file_h%d file_l%d map_ln%d\n", new_w.width, \
	new_w.height, new_w.x_mid, new_w.y_mid, new_w.iso_p, new_w.file_w, new_w.file_h, new_w.file_l, new_w.map_ln);
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
	int				i;

	printf("\n-------fdf_draw start-------\n");
	i = 0;
	mlx_key_hook(new_w->win_p, fdf_keys, new_w);
	fdf_mv_find(new_w);
	fdf_redraw(new_w);
	mlx_loop(new_w->mlx_p);
	printf("-------fdf_draw end-------\n");
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