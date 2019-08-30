/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/30 04:59:29 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

static void		fdf_ln_sz(t_w *new_w)
{
	if (new_w->file_w > 450)
		new_w->map_ln = 4;
	else if (new_w->file_w > 250)
		new_w->map_ln = 6;
	else if (new_w->file_w > 100)
		new_w->map_ln = 8;
	else
		new_w->map_ln = 15;
}

/*
** **************************************************************************
**	int file_to_arr(char *s, int i)
**	Function to store coords
**	while //printf("buff[%d]=%s, tmp_z[%d]= %d", x, buff[x], x, tmp_z[x]);
** **************************************************************************
*/

static void		file_to_arr(t_w *new_w, char *s, int y)
{
	char	**buff_splt;
	int		i;
	int		x;

	i = 0;
	x = 0;
	buff_splt = ft_strsplit(s, ' ');
	while (buff_splt[x] != '\0')
		x++;
	while (i < x)
	{
		new_w->p[new_w->p_nb].x = new_w->map_ln * i;
		new_w->p[new_w->p_nb].y = new_w->map_ln * y;
		new_w->p[new_w->p_nb].z = new_w->map_ln * ft_atoi(buff_splt[i]);
		new_w->p_nb++;
		i++;
	}
}

int				count_points(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] > 32) && (s[i + 1] <= 32))
			count++;
		i++;
	}
	return (count);
}

/*
** **************************************************************************
**	static int fdf_read(t_crds all_ps[260000], int fd)
**	Function to read files
** **************************************************************************
*/

static void		fdf_more_read(t_read *r, t_w *new_w)
{
	while (r->gnl_res)
	{
		if ((r->gnl_res = get_next_line(r->fd, &r->buff)) && (r->gnl_res == -1))
		{
			ft_putstr_fd("GNL read error", 2);
			ft_strdel(&r->buff);
			exit(1);
		}
		if (r->buff)
			r->buff = ft_strjoin(r->buff, r->new_line);
		if (r->count == -1)
			r->count = count_points(r->buff);
		if (new_w->file_w == 0)
		{
			new_w->file_w = ft_strlen(r->buff);
			fdf_ln_sz(new_w);
		}
		if (r->buff)
			r->line = ft_strjoin_del(r->line, r->buff, 2);
		r->y++;
		if (new_w->file_w == 0)
			new_w->file_w = ft_strlen(r->buff);
	}
}

static void		fdf_read(int fd, t_w *new_w)
{
	t_read	r;
	int		i;

	r.fd = fd;
	new_w->p_nb = 0;
	new_w->file_w = 0;
	r.count = -1;
	r.y = -1;
	r.line = "\0";
	r.new_line = "\n";
	r.gnl_res = 1;
	fdf_more_read(&r, new_w);
	new_w->p = (t_crds *)malloc(sizeof(t_crds) * r.count * r.y);
	r.lines = ft_strsplit(r.line, '\n');
	i = 0;
	while (i < r.y)
	{
		file_to_arr(new_w, r.lines[i], i);
		i++;
	}
}

/*
** **************************************************************************
**	static int fdf_open(char *source_f)
**	function to open files
** **************************************************************************
*/

static int		fdf_open(char *source_f)
{
	int			fd;

	if ((fd = open(source_f, O_RDONLY)) < 0)
	{
		ft_putstr_fd("open error", 2);
		exit(1);
	}
	return (fd);
}

/*
** **************************************************************************
**	int main(int argc, char **argv)
**	function to get user map
** **************************************************************************
*/

int				main(int argc, char **argv)
{
	t_w			new_w;
	int			fd;

	if (argc != 2 || (argv[1] == NULL))
	{
		ft_putstr("usage: ./fdf source_file\n");
		exit(1);
	}
	//fd = fdf_open(argv[1]);
	fd = fdf_open("maps/42.fdf");
	new_w.f_name = argv[1];
	fdf_read(fd, &new_w);
	fdf_new_win(&new_w);
	fdf_draw(&new_w);
	close(fd);
	exit(0);
}
