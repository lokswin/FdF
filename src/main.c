/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/31 21:06:15 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_ln_sz(t_w *new_w)
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
**	static int fdf_read(t_crds all_ps[260000], int fd)
**	Function to read files
** **************************************************************************
*/

static void	fdf_more_read(t_read *r, t_w *new_w)
{
	char *tmp;
	char *saved;

	saved = ft_strnew(0);
	while (r->gnl_res)
	{
		fdf_gnl(r, new_w);
		if (r->buff)
		{
			tmp = r->buff;
			r->buff = ft_strjoin(r->buff, r->new_line);
			ft_strdel(&tmp);
			tmp = saved;
			saved = ft_strjoin(saved, r->buff);
			ft_strdel(&tmp);
		}
		r->y++;
		if (new_w->file_w == 0)
			new_w->file_w = ft_strlen(r->buff);
		ft_strdel(&r->buff);
	}
	r->line = ft_strdup(saved);
	ft_strdel(&saved);
	ft_strdel(&tmp);
}

static void	fdf_read(int fd, t_w *new_w)
{
	t_read	r;
	int		i;

	r.fd = fd;
	new_w->p_nb = 0;
	new_w->file_w = -1;
	r.count = -1;
	r.y = -1;
	r.new_line = "\n";
	r.gnl_res = 1;
	fdf_more_read(&r, new_w);
	new_w->p = (t_crds *)malloc(sizeof(t_crds) * r.count * r.y);
	r.lines = ft_strsplit(r.line, '\n');
	ft_strdel(&r.line);
	i = 0;
	new_w->mv = r.count;
	while (i < r.y)
	{
		file_to_arr(new_w, r.lines[i], i);
		i++;
	}
	ft_clean_map(r.lines);
}

/*
** **************************************************************************
**	static int fdf_open(char *source_f)
**	function to open files
** **************************************************************************
*/

static int	fdf_open(char *source_f)
{
	int		fd;

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

int			main(int argc, char **argv)
{
	t_w			new_w;
	int			fd;

	if (argc != 2 || (argv[1] == NULL))
	{
		ft_putstr("usage: ./fdf source_file\n");
		exit(1);
	}
	fd = fdf_open(argv[1]);
	new_w.f_name = argv[1];
	fdf_read(fd, &new_w);
	fdf_console_man();
	fdf_new_win(&new_w);
	fdf_draw(&new_w);
	close(fd);
	exit(0);
}
