/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/16 19:30:09 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	void fdf_rotate_xy(int *x, int *y, int z, int iso_p)
**	Function for map rotation
** **************************************************************************
*/

void		fdf_rotate_xy(int *x, int *y, int z, int iso_p)
{
	float	angle;
	int		tmp_x;
	int		tmp_y;

	printf("\n-------fdf_rotate_xy start-------\n");
	angle = 0.523599;//0.46373398
	tmp_x = *x;
	tmp_y = *y;
	if (iso_p == 1)//Slanting left:
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
	else if (iso_p == 0)
	{
		*x = (tmp_x - tmp_y) * cos(angle);
		*y = (tmp_x + tmp_y) * sin(angle) - z;
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
	mlx_destroy_image(new_w->mlx_p, new_w->img_p);
	mlx_clear_window(new_w->mlx_p, new_w->win_p);
	new_w->img_p = NULL;
	new_w->img = NULL;
	fdf_ui(new_w, 0);
	new_w->img_p = mlx_new_image(new_w->mlx_p, 400, 400);
	new_w->img = mlx_get_data_addr(new_w->img_p, \
	&new_w->bitspp, &new_w->ln_sz, &new_w->endi);
	while (i < (new_w->p_nb - 1))
	{
		//new_w->img = new_w->img + new_w->ln_sz;
		fdf_dw_ln(new_w->point, *new_w, i, new_w->p_nb - 1);
		i++;
	}
	mlx_put_image_to_window(new_w->mlx_p, new_w->win_p, new_w->img_p, 800, 400);
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
