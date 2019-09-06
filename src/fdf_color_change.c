/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:33:17 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/30 02:43:14 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		get_line_pnt(double start, double end, double current)
{
	if (current == start)
		return (0.0);
	if (current == end)
		return (1.0);
	if (start == end)
		return (0.0);
	return ((current - start) / (end - start));
}

void		fdf_color_change(t_w *new_w)
{
	new_w->max_color += 5000;
	new_w->min_color += 1000;
}

static void	fdf_change_color_more(t_w *new_w)
{
	if (new_w->color_style == 5)
	{
		new_w->max_color = 0xFF8C00;
		new_w->min_color = 0xFF8C00;
	}
	if (new_w->color_style == 6)
	{
		new_w->max_color = 0x1E90FF;
		new_w->min_color = 0x1E90FF;
	}
	if (new_w->color_style == 7)
	{
		new_w->max_color = 0xFF8C00;
		new_w->min_color = 0x00FF00;
	}
	if (new_w->color_style == 8)
	{
		new_w->max_color = 0xFFFFFF;
		new_w->min_color = 0x3CB377;
	}
	if (new_w->color_style == 9)
	{
		new_w->max_color = 0x3CB377;
		new_w->min_color = 0x8B008B;
	}
}

void		fdf_change_color(t_w *new_w)
{
	if (new_w->color_style == 0 || new_w->color_style == 1)
	{
		new_w->max_color = new_w->color_style == 0 ? 0xFFFFFF : 0xFF0000;
		new_w->min_color = new_w->color_style == 0 ? 0xFFFFFF : 0x0000FF;
	}
	if (new_w->color_style == 2)
	{
		new_w->max_color = 0x00FF00;
		new_w->min_color = 0x0000FF;
	}
	if (new_w->color_style == 3)
	{
		new_w->max_color = 0xFFFFFF;
		new_w->min_color = 0x0000FF;
	}
	if (new_w->color_style == 4)
	{
		new_w->max_color = 0xFF0000;
		new_w->min_color = 0x00FF00;
	}
	fdf_change_color_more(new_w);
}
