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
//# define ABS(var)((var) < 0 ? -(var) : (var))

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
	struct s_crds	*next;
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
	char			*img;
	int				width;
	int				height;
	int				color;
	int				ln_sz;
	int				bitspp;
	int				endi;
	int				iso_p;
	int				p_nb;
	t_crds			*point;
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
}					t_w;

void				fdf_new_win(t_w *new_w, int ln_nb, char *source_f);

int					fdf_find_x(t_crds line, float y, float x, int i);
int					fdf_dw_ln(t_crds *point, t_w new_w, int p1, int p2);
int					fdf_draw(t_crds all_lns[512], int ln_nb, char *source_f);

int					fdf_keys(int key, void *param);
t_w					*fdf_ui(t_w *new_w, int first_time);

void				delay(int number_of_seconds);
void				fdf_p_struct(t_crds all_lns[512], int ln_nb);

int					fdf_reform_xy(t_w new_w, int x, int y);
void				fdf_rotate_xy(int *x, int *y, int z, int dir);
int					fdf_redraw(t_w *new_w);

#endif