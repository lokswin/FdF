/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/16 20:53:58 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	void fdf_dw_ln(t_crds *point, t_w new_w, int p1, int p2)
**	Function to draw one line betwen p1 and p2
** **************************************************************************
*/

int			fdf_dw_ln(t_crds *all_ps, t_w new_w, int p1, int p2)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		step;
	int		i;

	printf("\n-------fdf_dw_ln start--p1=%d; p2=%d\n", p1, p2);
	x1 = all_ps[p1].x;
	y1 = all_ps[p1].y;
	x2 = all_ps[p2].x;
	y2 = all_ps[p2].y;
	//fdf_rotate_xy(&x1, &y1, point[p_nb].z, new_w.iso_p);
	fdf_rotate_xy(&x1, &y1, all_ps[p1].z, new_w.iso_p);
	fdf_rotate_xy(&x2, &y2, all_ps[p2].z, new_w.iso_p);
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) >= abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	dx = dx / step;
	dy = dy / step;
	while(step--)
	{
		//printf("x1=%d, y1=%d, step=%d, dx=%d, dy=%d\n", x1, y1, step, dx, dy);
	
		i = (x1 * (new_w.bitspp / 8)) + (y1 * new_w.ln_sz);
		new_w.img[i] = new_w.color; // B — Blue
		new_w.img[++i] = new_w.color >> 8; // G — Green
		new_w.img[++i] = new_w.color >> 16; // R — Red
		new_w.img[++i] = 0;
		x1 = x1 + dx;
    	y1 = y1 + dy;
	}
	printf("-------fdf_dw_ln end-------");
	return (1);
	
}

/*
** **************************************************************************
**	int fdf_draw(t_crds all_ps[512], int p_nb, char *source_f)
**	Function to draw
** **************************************************************************
*/

int					fdf_draw(t_crds all_ps[512], int p_nb, char *source_f)
{
	t_w				new_w;
	int				i;
	int				mv;


	printf("\n-------fdf_draw start-------\n");
	i = 0;
	fdf_new_win(&new_w, p_nb, source_f);
	new_w.point = all_ps;
	mlx_key_hook(new_w.win_p, fdf_keys, &new_w);
	mv = fdf_find(all_ps, p_nb) + 1;
	while (i < (p_nb - 1))
	{
		fdf_dw_ln(all_ps, new_w, i, i + 1);//horiz
	 	if (((i + mv) > 0) && ((i + mv) < p_nb))
		{
			fdf_p_struct(all_ps, i);
			fdf_dw_ln(all_ps, new_w, i, i + mv);//vert
		}
		i++;
	}
	mlx_put_image_to_window(new_w.mlx_p, new_w.win_p, new_w.img_p, 200, 200);
	mlx_loop(new_w.mlx_p);
	printf("-------fdf_draw end-------\n");
	return (0);
}

/*
** **************************************************************************
**	int fdf_find()
**	Function to find next line point
** **************************************************************************
*/

int				fdf_find(t_crds all_ps[512], int p_nb)
{
	int			tmp;
	int			i;

	printf("-------fdf_find start-------\n");
	tmp = all_ps[0].x;
	i = 0;
	while (i < (p_nb - 1))
	{
		if (all_ps[i].x > tmp)
			tmp = all_ps[i].x;
		i++;
	}
	tmp = tmp / 10;
	printf("-------fdf_find end-------\n");
	return (tmp);
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
