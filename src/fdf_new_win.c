/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/31 21:03:46 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_xy_mid(t_w *new_w)
{
	new_w->width = 2000;
	new_w->height = 1100;
	new_w->x_mid = 600;
	new_w->y_mid = 500;
}

/*
** **************************************************************************
**	int fdf_new_win(t_w *new_w, int p_nb, char *source_f)
**	Function to initialize window and image in struct t_w new_w
** **************************************************************************
*/

void		fdf_new_win(t_w *new_w)
{
	fdf_initials(new_w);
	fdf_xy_mid(new_w);
	if (!(new_w->mlx_p = mlx_init()))
	{
		ft_putstr_fd("mlx error", 2);
		exit(1);
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
