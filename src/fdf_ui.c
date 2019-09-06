/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_ui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/09/01 17:27:47 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	static void fdf_ui_man(t_w *new_w)
**	Function draw instructions
** **************************************************************************
*/

static void		fdf_more_ui_man(t_w *new_w)
{
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 205, 0xFFFFFF, "    + -     : Altitude");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 225, 0xFFFFFF, "    C V     : Change color");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 245, 0xFFFFFF, "    ESC     : Quit");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 265, 0xFFFFFF, "    SPACE   : Reset");
}

static void		fdf_ui_man(t_w *new_w)
{
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 45, 0x00FF00, "   *****FdF by nshelly & drafe *****");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 65, 0xFFFFFF, "    v ^     : Zoom");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 85, 0xFFFFFF, "    < >     : Rotation around Z-axis");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 105, 0xFFFFFF, "    u i     : Rotation around Y-axis");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 125, 0xFFFFFF, "    j k     : Rotation around X-axis");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 145, 0xFFFFFF, "    A D     : Move Z-axis");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 165, 0xFFFFFF, "    W S     : Move Y-axis");
	mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 185, 0xFFFFFF, "    Q E     : Move X-axis");
	fdf_more_ui_man(new_w);
}

/*
** **************************************************************************
**    static void fdf_ui_back(t_w new_w)
**    Function draw background of FdF header
** **************************************************************************
*/

static void		fdf_ui_back(t_w *new_w)
{
	int	i;
	int	j;

	i = 0;
	while (i < 35)
	{
		j = 0;
		while (j < new_w->width - 1)
		{
			mlx_pixel_put(new_w->mlx_p, new_w->win_p, j, i, new_w->max_color);
			if (!(j % 28))
				mlx_pixel_put(new_w->mlx_p, new_w->win_p, j, i, 0xFFC300);
			j++;
		}
		i++;
	}
	fdf_ui_man(new_w);
}

/*
** **************************************************************************
**	static int fdf_name_len(t_w new_w)
**	Function to count file name length
** **************************************************************************
*/

static size_t	fdf_name_len(t_w *new_w)
{
	size_t	name_len;
	size_t	new_len;

	new_len = (new_w->width / 10) - 13;
	name_len = (ft_strlen(new_w->f_name) + 5) * 10;
	if ((name_len > (size_t)new_w->width) && (new_w->width > 80)\
			&& (new_len > 0))
	{
		new_w->f_name = ft_strsub(new_w->f_name, 0, new_len);
		new_w->f_name = ft_strcat(new_w->f_name, "...");
		name_len = (ft_strlen(new_w->f_name) + 5) * 10;
	}
	return (name_len);
}

/*
** **************************************************************************
**	int fdf_ui(void *mlx_p, void *win_p)
**	Function to draw FdF UI
** **************************************************************************
*/

t_w				*fdf_ui(t_w *new_w, int first_time)
{
	size_t		n_len;

	n_len = fdf_name_len(new_w);
	if (first_time)
		if (n_len <= (size_t)new_w->width)
		{
			new_w->win_p = mlx_new_window(new_w->mlx_p, \
			new_w->width, new_w->height, ft_strcat(new_w->f_name, " - FdF"));
			fdf_ui_back(new_w);
			mlx_string_put(new_w->mlx_p, new_w->win_p, \
			((new_w->width - n_len) / 2), 5, 0x2EE13F, new_w->f_name);
		}
		else
			new_w->win_p = mlx_new_window(new_w->mlx_p, \
			new_w->width, new_w->height, "FdF");
	else if (n_len <= (size_t)new_w->width)
	{
		fdf_ui_back(new_w);
		mlx_string_put(new_w->mlx_p, new_w->win_p, \
		((new_w->width - n_len) / 2), 5, 0x2EE13F, new_w->f_name);
	}
	return (new_w->win_p);
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
