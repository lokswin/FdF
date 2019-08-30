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

double	get_line_pnt(double start, double end, double current)
{
	if (current == start)
		return (0.0);
	if (current == end)
		return (1.0);
	if (start == end)
		return (0.0);
	return ((current - start) / (end - start));
}

void	fdf_color_change(t_w *new_w)
{
	new_w->max_color += 5000;
	new_w->min_color += 1000;
}
