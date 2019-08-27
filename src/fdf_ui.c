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
			45, 45, 0x00FF00, "***FdF by nshelly & drafe ***");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 65, 0xFFFFFF, "    < > v ^ : Rotation");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 85, 0xFFFFFF, "    c       : Color");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 105, 0xFFFFFF, "    W A S D : Move");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 125, 0xFFFFFF, "    + -     : Altitude");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 145, 0xFFFFFF, "    ESC     : Quit");
    mlx_string_put(new_w->mlx_p, new_w->win_p, \
			45, 165, 0xFFFFFF, "    SPACE   : Reset");
    ft_putstr("\n\t*** FdF by nshelly & drafe ***\n\n Man:\n\
	\t< > v ^ : Rotation\n\t\tW A S D\t: Move\n\t\t+ -     : Altitude\n\
	\tc       : Color\n\t\tESC     : Quit\n\t\tSPACE   : Reset");
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
		while (j < new_w->width)
		{
			mlx_pixel_put(new_w->mlx_p, new_w->win_p, j, i, 0xFFFFFF);
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

static size_t		fdf_name_len(t_w *new_w)
{
	size_t			name_len;
	size_t			new_len;
	char			*tmp;

	tmp = NULL;
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
**	int fdf_ui(void *mlx_p, void *win_p)
**	Function which allow users to control FdF with keyboard
** **************************************************************************
*/

int			fdf_keys(int key, void *param)
{
	t_w		*new_w;

	new_w = (t_w *)param;
	if ((key >= 123) && (key <= 126))
	{
		new_w->iso_p = key - 123;
		ft_putnbr(new_w->iso_p);
		new_w->angle = new_w->angle + 5;
		fdf_redraw(new_w);
	}
    if (key == 78)//+
    {
        new_w->mv_z = new_w->mv_z - 5;
        fdf_redraw(new_w);
    }
    if (key == 69)//-
    {
        new_w->mv_z = new_w->mv_z + 5;
        fdf_redraw(new_w);
    }
    if (key == 2)// D
    {
        new_w->mv_x = new_w->mv_x + 5;
        new_w->mv_y = new_w->mv_y + 5;//rigth move
        fdf_redraw(new_w);
    }
    if (key == 0)//A
    {
        new_w->mv_x = new_w->mv_x - 5;//left move
        new_w->mv_y = new_w->mv_y - 5;
        fdf_redraw(new_w);
    }
    if (key == 13)//W
    {
        new_w->mv_y = new_w->mv_y - 5;
        new_w->mv_x = new_w->mv_x + 5;
        fdf_redraw(new_w);
    }
    if (key == 1)//S
    {
        new_w->mv_y = new_w->mv_y + 5;
        new_w->mv_x = new_w->mv_x - 5;
        fdf_redraw(new_w);
    }
    if (key == 49)//Space
    {
        new_w->mv_x = 0;
        new_w->mv_y = 0;
        new_w->mv_z = 0;
        new_w->iso_p = 0;
        new_w->angle = 26.4;//0.46373398 ;
        new_w->max_color = 0xFFFFFF;
        new_w->min_color = 0xFFFFFF;
        fdf_redraw(new_w);
    }
    if (key == 8)//c
    {
        fdf_color_change(new_w);
        fdf_redraw(new_w);
    }
	if (key == 53)
		exit(0);
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
