/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/18 20:04:58 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	void fdf_rotate_xy(int *x, int *y, int z, int iso_p)
**	Function for map rotation
** **************************************************************************
*/

void		fdf_rotate_xy(double *x, double *y, double z, int iso_p)
{
	double	angle;
	double	tmp_x;
	double	tmp_y;

	printf("\n-------fdf_rotate_xy start-------\n");
	angle = 0.46373398;//0.523599;//30;
	tmp_x = *x;
	tmp_y = *y;
	if (iso_p == 0)//Slanting right:
	{
		*x = (tmp_x + tmp_y) * cos(angle);
		*y = (tmp_x - tmp_y) * sin(angle) - z;
	}
	else if (iso_p == 1)//Slanting left:
	{
		*x = (tmp_x - tmp_y) * -cos(angle);
		*y = ((tmp_x + tmp_y) * sin(angle)) - z;
	}
	else if (iso_p == 2)//Mirror image slanting right:
	{
		*x = (tmp_x - tmp_y) * cos(angle);
		*y = ((tmp_x + tmp_y) * sin(angle)) - z;
	}
	else if (iso_p == 3)//Mirror image slanting left:
	{
		*x = (tmp_x + tmp_y) * -cos(angle);
		*y = ((tmp_x - tmp_y) * sin(angle)) - z;
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
	mlx_destroy_image(new_w->mlx_p, new_w->img_p);
	new_w->img_p = NULL;
	new_w->img = NULL;
	fdf_ui(new_w, 0);
	new_w->img_p = mlx_new_image(new_w->mlx_p, 1300, 1300);
	new_w->img = mlx_get_data_addr(new_w->img_p, \
	&new_w->bitspp, &new_w->ln_sz, &new_w->endi);
	/*fdf_dw_ln(new_w->point, *new_w, i, i + 1);*/
	 while (i < (new_w->p_nb - 1))
	{
		//if (new_w->point[i].y == (new_w->point[i].y + 1))
			fdf_dw_ln(new_w->point, *new_w, i, i + 1);
		
		if (((i + new_w->mv) > 0) && ((i + new_w->mv) < new_w->p_nb))
		{
			fdf_dw_ln(new_w->point, *new_w, i, i + new_w->mv);//vert lines
		}
		i++;
	}
	//mlx_put_image_to_window(new_w->mlx_p, new_w->win_p, new_w->img_p, 100, 100);
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
