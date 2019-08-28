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

typedef struct		s_crds
{
	int				x;
	int				y;
	int				z;
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
	int				file_h;
    int             file_l;
    int				width;
	int				height;
	int				x_mid;
	int				y_mid;
	int             mv_x;
    int             mv_y;
    int             mv_z;
	int				map_ln;
	int				color;
	int				iso_p;
	int				p_nb;
	int				mv;
	double			angle;
	t_crds			*p;
	void			*mlx_p;
	void			*win_p;
    int         max_color;
    int         min_color;
    int         max_z;
    int         min_z;

}					t_w;

void				fdf_new_win(t_w *new_w);
int					fdf_dw_ln(t_crds *p, t_w new_w, int p1, int p2);
int					fdf_draw(t_w *new_w);
int					fdf_keys(int key, void *param);
t_w					*fdf_ui(t_w *new_w, int first_time);
void				fdf_rotate_xy(double *x, double *y, double z, t_w *new_w);
int					fdf_redraw(t_w *new_w);
void	        	fdf_speed_up(t_w *new_w);
void    max_min(t_w *new_w);
void                set_colors(t_w *new_w);
int                 color_lint(int c1, int c2, double decimal_percent);
double		get_line_pnt(double start, double end, double curr);
void    fdf_color_change(t_w *new_w);


#endif