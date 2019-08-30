/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:12:09 by drafe             #+#    #+#             */
/*   Updated: 2019/07/25 17:25:40 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "./libft/libft.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>

/*
** **************************************************************************
**	typedef struct s_crds
**	Structure for store point coordinates
** **************************************************************************
*/

typedef struct		s_draw
{
    double	x1;
    double	y1;
    double  x2;
    double  y2;
    double	dx;
    double	dy;
    int		step;
    double  dx2;
    double  dy2;
    double  x_n;
    double  y_n;
    double     decimal;
}					t_draw;

typedef struct		s_read
{
    char		*buff;
    int			gnl_res;
    int			y;
    char        *line;
    int         count;
    char        **lines;
    char        *new_line;
    int         fd;
}					t_read;

typedef struct		s_crds
{
    double				x;
    double			    y;
    double				z;
	int             color;
}					t_crds;

/*
** **************************************************************************
**	typedef struct s_w
**	Structure for store window settings
** **************************************************************************
*/

typedef struct		s_w
{
	char			*f_name;
	int				file_w;
    int				width;
	int				height;
	int				x_mid;
	int				y_mid;
	int             mv_x;
    int             mv_y;
    int             mv_z;
    int             mv_z2;
	int				map_ln;
	int				color;
	int				iso_p;
	int				p_nb;
    int				mv;
	double			angle;
	double          angle_x;
    double          angle_y;
	t_crds			*p;
	void			*mlx_p;
	void			*win_p;
    int         max_color;
    int         min_color;
    double         max_z;
    double        min_z;
    int         m;
}					t_w;

void				fdf_new_win(t_w *new_w);
int			fdf_dw_ln(t_w *new_w, int p1, int p2);
int					fdf_draw(t_w *new_w);
int					fdf_keys(int key, void *param);
int			fdf_keys1(int key, void *param);
t_w					*fdf_ui(t_w *new_w, int first_time);
void				fdf_rotate_xy(double *x, double *y, double z, t_w *new_w);
int					fdf_redraw(t_w *new_w);
void	        	fdf_speed_up(t_w *new_w);
void    max_min(t_w *new_w);
void                set_colors(t_w *new_w);
int                 color_lint(int c1, int c2, double decimal_percent);
double		get_line_pnt(double start, double end, double curr);
void    fdf_color_change(t_w *new_w);
void fdf_initials(t_w *new_w);

#endif