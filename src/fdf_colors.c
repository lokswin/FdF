/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <nshelly@student.21school.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:33:17 by nshelly           #+#    #+#             */
/*   Updated: 2019/08/19 22:33:28 by nshelly          ###   ########.fr       */
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


t_maxmin    max_min(t_crds all_sp[260000], int p_nb)
{
    int i;
    t_maxmin minmax;

    i = 0;
    minmax.max_z =0;
    minmax.min_z =0;
    minmax.max_color = 0xFF0000;
    minmax.min_color = 0x0000FF;
    while(i < p_nb - 1)
    {
        if (all_sp[i].z > all_sp[i+1].z)
            minmax.max_z = all_sp[i].z;
        if (all_sp[i].z < all_sp[i+1].z)
            minmax.min_z = all_sp[i].z;
        i++;
    }
    return(minmax);
}

static double		ft_lint(double start, double end, double decimal_percent)
{
    if (start == end)
        return (start);
    return (start * (1.0 - decimal_percent) + (end * decimal_percent));
    //return (start + decimal_percent * (end - start));
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

int			color_lint(int c1, int c2, double decimal_percent)
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

static int calc_point_color(t_maxmin climits, int z)
{
    int color;
    double divisor;
    double dec_pcnt;

    divisor = climits.max_z - climits.min_z;
    if(divisor != 0)
        dec_pcnt  = (z - climits.min_z) / divisor;
    else
        dec_pcnt = 0.0;
    color = color_lint(climits.min_color, climits.max_color, dec_pcnt);
    return (color);
}

void    set_colors(t_maxmin min_max, t_crds all_ps[260000], int p_nb)
{
    int i;

    i = 0;
    while(i < p_nb)
    {
        all_ps[i].color = calc_point_color(min_max, all_ps[i].z);
        i++;
    }
}