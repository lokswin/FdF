/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_ui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/19 20:30:21 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	static void fdf_ui_man(t_w *new_w)
**	Function draw instructions
** **************************************************************************
*/

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
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 205, 0xFFFFFF, "    + -     : Altitude");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 225, 0xFFFFFF, "    C       : Change color");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 245, 0xFFFFFF, "    ESC     : Quit");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 265, 0xFFFFFF, "    SPACE   : Reset");
    ft_putstr("\n\t*** FdF by nshelly & drafe ***\n\n Man:\n\
	\t^ v     : Zoom\n\t< >     : Rotation arount Z-axis\n\tu i     : Rotation arount Y-axis\n\tj k     : Rotation arount X-axis\n\t\tA D    \t: Move X-axis\n\t\tW S    \t: Move \
Y-axis\n\t\tQ E    \t: Move Z-axis\n\t\t+ -     : Altitude\n\
	\tc       : Change color\n\t\tESC     : Quit\n\t\tSPACE   : Reset");
}

/*
** **************************************************************************
**    static void fdf_ui_back(t_w new_w)
**    Function draw background of FdF header
** **************************************************************************
*/

static void		fdf_ui_back(t_w *new_w)
{
	int		i;
	int		j;

	i = 0;
	while (i < 35)
	{
		j = 0;
		while (j < new_w->width - 1)
		{
			mlx_pixel_put(new_w->mlx_p, new_w->win_p, j, i, new_w->max_color);
			if (!(j % 28))
			{
                mlx_pixel_put(new_w->mlx_p, new_w->win_p, j, i, 0xFFC300);
                mlx_pixel_put(new_w->mlx_p, new_w->win_p, j++, i, 0xFFC300);
                mlx_pixel_put(new_w->mlx_p, new_w->win_p, j++, i, 0xFFC300);
                mlx_pixel_put(new_w->mlx_p, new_w->win_p, j++, i, 0xFFC300);
                mlx_pixel_put(new_w->mlx_p, new_w->win_p, j++, i, 0xFFC300);
            }
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

static size_t		fdf_name_len(t_w *new_w)
{
	size_t			name_len;
	size_t			new_len;

	new_len = (new_w->width / 10) - 13;
	name_len = (ft_strlen(new_w->f_name) + 5) * 10;
	if ((name_len > (size_t)new_w->width) && (new_w->width > 80) && (new_len > 0))
	{
		new_w->f_name = ft_strsub(new_w->f_name, 0, new_len);
		new_w->f_name = ft_strcat(new_w->f_name, "...");
		name_len = (ft_strlen(new_w->f_name) + 5) * 10;
	}
	return (name_len);
}

/*
** **************************************************************************
**	int fdf_keys(int key, void *param)
**	Function which allow users to control FdF with keyboard
 * numbers  : keys
 * 123,124 : <,>
 * 38, 40  : j,k
 * 32, 34  : u,i
 * 126,125 : ^,v
 * 78,69   : +,-
 * 12, 14  : q, z
 * 2 , 0   : d, a
 * 13, 1   : w, s
 * 49      : space
 * 8       : c
 * 53      : esc
** **************************************************************************
*/

int			fdf_keys(int key, void *param)
{
	t_w		*new_w;
    double  a;

    a = 5 * (M_PI / 180);
	new_w = (t_w *)param;
    if (key == 123 || key == 124)
        new_w->angle = key == 123 ? (new_w->angle + a) : (new_w->angle - a);
    if (key == 38 || key == 40)
    {
        new_w->angle_x = key == 38 ? (new_w->angle_x + a) : (new_w->angle_x - a);
        new_w->angle_y = 0;
    }
    if (key == 32 || key == 34)
    {
        new_w->angle_y = key == 32 ? (new_w->angle_y + a) : (new_w->angle_y - a);
        new_w->angle_x = 0;
    }
    if (key == 126 || (key == 125 && new_w->m > 1))
        new_w->m = key == 126 ? (new_w->m + 1) : (new_w->m - 1);
    if (key == 78 || key == 69)
        new_w->mv_z = key == 78 ? new_w->mv_z - 5 : new_w->mv_z + 5;
    if (key == 12 || key == 14)
        new_w->mv_z2 = key == 12 ? new_w->mv_z2 + 5 : new_w->mv_z2 - 5;
    if (key == 2 || key == 0)
        new_w->mv_x = key == 2 ? new_w->mv_x + 5 : new_w->mv_x - 5;;
    if (key == 13 || key == 1)
        new_w->mv_y = key == 13 ? new_w->mv_y - 5 : new_w->mv_y + 5;;
    if (key == 49)
        fdf_initials(new_w);
    if (key == 8)
        fdf_color_change(new_w);
	if (key == 53)
		exit(0);
    fdf_redraw(new_w);
	return ((int)param);
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
			new_w->win_p = mlx_new_window(new_w->mlx_p, new_w->width, new_w->height, "FdF");
	else
		if (n_len <= (size_t)new_w->width)
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
