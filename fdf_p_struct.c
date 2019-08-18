/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/18 19:57:42 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	void fdf_p_struct(t_crds all_ps[260000], int p_nb)
**	Function to print one structure node
**
** **************************************************************************
*/

void		fdf_p_struct(t_crds all_ps[260000], int p_nb)
{
	int		i;
	int		j;

	printf("\n-------fdf_p_struct start-------\n");
	i = 0;
	j = 0;

	printf("all_ps[%d] x=%d y=%d z=%d\n", \
	p_nb, all_ps[p_nb].x, all_ps[p_nb].y, all_ps[p_nb].z);
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
