/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:33:17 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/30 02:49:17 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			max_min(t_w *new_w)
{
	int i;

	i = 0;
	new_w->max_z = new_w->p[i].z;
	new_w->min_z = new_w->p[i].z;
	while (i < new_w->p_nb)
	{
		if (new_w->max_z < new_w->p[i].z)
			new_w->max_z = new_w->p[i].z;
		if (new_w->min_z > new_w->p[i].z)
			new_w->min_z = new_w->p[i].z;
		i++;
	}
}

static double	ft_lint(double start, double end, double decimal_percent)
{
	if (start == end)
		return (start);
	return (start * (1.0 - decimal_percent) + (end * decimal_percent));
}

/*
**	color_lint - generates an intermediate color between c1 and c2.
**
**	Colors are stored in the following hex format:
**	0 x |  F F  |   F F   |  F F  |
**	    |  red  |  green  | blue  |
**
**	So what we can do is mask and isolate each color channel using bit shifting
**	and perform linear interpolation on each channel before recombining.
**
**	Each channel is 8 bits.
*/

int				color_lint(int c1, int c2, double decimal_percent)
{
	int	r;
	int	g;
	int	b;

	if (c1 == c2)
		return (c1);
	if (decimal_percent == 0.0)
		return (c1);
	if (decimal_percent == 1.0)
		return (c2);
	r = (int)ft_lint(((c1 >> 16) & 0xFF), ((c2 >> 16) & 0xFF), decimal_percent);
	g = (int)ft_lint(((c1 >> 8) & 0xFF), ((c2 >> 8) & 0xFF), decimal_percent);
	b = (int)ft_lint((c1 & 0xFF), (c2 & 0xFF), decimal_percent);
	return (r << 16 | g << 8 | b);
}

static int		calc_point_color(t_w *new_w, int i)
{
	int		color;
	double	divisor;
	double	dec_pcnt;

	divisor = new_w->max_z - new_w->min_z;
	if (divisor != 0)
		dec_pcnt = (new_w->p[i].z - new_w->min_z) / divisor;
	else
		dec_pcnt = 0.0;
	color = color_lint(new_w->min_color, new_w->max_color, dec_pcnt);
	return (color);
}

void			set_colors(t_w *new_w)
{
	int i;

	i = 0;
	while (i < new_w->p_nb)
	{
		new_w->p[i].color = calc_point_color(new_w, i);
		i++;
	}
}
