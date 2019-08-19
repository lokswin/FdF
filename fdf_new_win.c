/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/18 17:52:15 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	int fdf_new_win(t_w *new_w, int p_nb, char *source_f)
**	Function to initialize window and image in struct t_w new_w
** **************************************************************************
*/

void		fdf_new_win(t_w *new_w, int p_nb, char *source_f)
{
	printf("\n-------fdf_new_win start-------\n");
	new_w->f_name = source_f;
	new_w->width = 1400;
	new_w->height = 1300;
	new_w->iso_p = 5;
	new_w->p_nb = p_nb;
	if (!(new_w->mlx_p = mlx_init()))
	{
		ft_putstr_fd("mlx error", 2);
		exit (1);
	}
	new_w->color = mlx_get_color_value(new_w->mlx_p, 0xFFFFFF);
	new_w->img_p = mlx_new_image(new_w->mlx_p, 1300, 1300);

	new_w->win_p = fdf_ui(new_w, 1);
	if (!new_w->mlx_p || !new_w->win_p || !new_w->img_p)
	{
		ft_putstr_fd("mlx error", 2);
		exit(1);
	}
	new_w->img = mlx_get_data_addr(new_w->img_p, \
	&new_w->bitspp, &new_w->ln_sz, &new_w->endi);
	printf("-------fdf_new_win end-------\n");
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
