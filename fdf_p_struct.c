/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/08 20:01:15 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	int fdf_find_xy(t_crds line, float y, float x, int i)
**	Function to print one structure node
**
** **************************************************************************
*/

void		fdf_p_struct(t_crds all_lns[512], int ln_nb)
{
	int		i;
	int		j;

	printf("\n-------fdf_p_struct start-------\n");
	i = 0;
	j = 0;

	printf("all_lns[%d] x=%d y=%d z=%d\n", \
	ln_nb, all_lns[ln_nb].x, all_lns[ln_nb].y, all_lns[ln_nb].z);
	printf("-------fdf_p_struct end-------");

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
