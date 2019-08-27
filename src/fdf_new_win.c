/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/19 21:23:56 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_xy_mid(t_w *new_w)
{
    int			w;
    int			h;
    int			max;

    printf("\n-------fdf_w_layout start-------\n");
    w = new_w->map_ln * new_w->file_w;
    h = new_w->map_ln * new_w->file_h;
    max = fmax(w, h);
    //if ((new_w->width = max + 80) % 2)
   //     new_w->width += 1;
    //if (new_w->width > 2500)
        new_w->width = 2500;
   // new_w->height =	(2 * h) + new_w->file_l + 50;
   // if (new_w->height > 1300)
        new_w->height = 1300;
    new_w->x_mid = 800;//new_w->width / 4;
    new_w->y_mid = 800;//new_w->height - (h / 2);

	//new_w->x_mid = ((new_w->width) - (new_w->file_w * (new_w->map_ln / 2))) / 2;
	//new_w->y_mid = 150 + ((new_w->height)) / 2;
}

/*
** **************************************************************************
**	int fdf_new_win(t_w *new_w, int p_nb, char *source_f)
**	Function to initialize window and image in struct t_w new_w
** **************************************************************************
*/

void		fdf_new_win(t_w *new_w)
{

    new_w->mv_x = 0;
    new_w->mv_y = 0;
    new_w->mv_z = 0;
    new_w->iso_p = 0;
    new_w->angle = 26.4;//0.46373398 ;
    new_w->max_color = 0xFFFFFF;
    new_w->min_color = 0xFFFFFF;
	fdf_xy_mid(new_w);
	if (!(new_w->mlx_p = mlx_init()))  
	{
		ft_putstr_fd("mlx error", 2);
		exit (1);
	}
	new_w->win_p = fdf_ui(new_w, 1);
	if (!new_w->mlx_p || !new_w->win_p)
	{
		ft_putstr_fd("mlx error", 2);
		exit(1);
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
