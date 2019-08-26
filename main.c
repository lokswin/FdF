/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/26 21:24:51 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			fdf_ln_sz(t_w *new_w)
{
	if (new_w->file_w > 450)
		new_w->map_ln = 4;
	else if (new_w->file_w > 250)
		new_w->map_ln = 6;
	else if (new_w->file_w > 100)
		new_w->map_ln = 8;
	else
		new_w->map_ln = 15;
	new_w->file_l = 0;
}

/*
** **************************************************************************
**	int file_to_arr(char *s, int i)
**	Function to store coords
**	//printf("buff[%d]=%s", x-1, buff[x-1]);
**	//printf("\nbuff[0]=%s tmp_z=%d one_line[i].x=%d i=%d x=%d\n",buff[0], tmp_z[x], one_line[i].x, i, x);
**	while //printf("buff[%d]=%s, tmp_z[%d]= %d", x, buff[x], x, tmp_z[x]);
** **************************************************************************
*/

static int			file_to_arr(t_w *new_w, char *s, int p_nb, int y)
{
	char			**buff_splt;
	int				i;
	int				x;

	printf("\n-------file_to_arr start-------\n");
	i = 0;
	x = 0;
	buff_splt = ft_strsplit(s, ' ');
	while (buff_splt[x] != '\0')
		x++;
	while (i < x)
	{	
		new_w->p[p_nb].next = &new_w->p[p_nb + 1];
		new_w->p[p_nb].x = new_w->map_ln * i;
		new_w->p[p_nb].y = new_w->map_ln * y;
		new_w->p[p_nb].z = new_w->map_ln * ft_atoi(buff_splt[i]);
		if (new_w->p[p_nb].z > new_w->file_l)
			new_w->file_l = new_w->p[p_nb].z;
		p_nb++;
		i++;
	}
	printf("-------file_to_arr end-------\n");
	return (p_nb);
}

/*
** **************************************************************************
**	static int fdf_read(t_crds all_ps[260000], int fd)
**	Function to read files
** **************************************************************************
*/

static int		fdf_read(int fd, t_w *new_w)
{
	char		*buff;
	int			gnl_res;
	int			y;
	int			p_nb;

	printf("\n-------fdf_read start-------\n");
	p_nb = 0;
	y = 0;
	gnl_res = 1;
	while (gnl_res)
	{
		if ((gnl_res = ft_get_next_line(fd, &buff)) && (gnl_res == -1))
		{
			ft_putstr_fd("GNL read error", 2);
			ft_strdel(&buff);
			exit(1);
		}
		if (new_w->file_w == 0)
		{
			new_w->file_w = ft_strlen(buff);
			fdf_ln_sz(new_w);
		}
		p_nb = file_to_arr(new_w, buff, p_nb, y++);
		
		ft_strdel(&buff);
	}
	new_w->file_h = y;
	new_w->p[p_nb - 1].next = NULL;
	printf("-------fdf_read end-------");
	return (p_nb);
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

	printf("\n-------fdf_open start-------\n");
	if ((fd = open(source_f, O_RDONLY)) < 0)
	{
		ft_putstr_fd("open error", 2);
		exit(1);
	}
	printf("-------fdf_open end------");
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
	t_crds		all_ps[260000];
	t_w			new_w;
	int			p_nb;
	int			fd;

	fd = 0;
	p_nb = 0;
	//all_ps = (t_crds*)malloc(sizeof(t_crds));
	if (argc != 2 || (argv[1] == NULL))
	{
		ft_putstr("usage: ./fdf source_file\n");
		exit(1);
	}
	ft_putstr("\n\t*** FdF by nshelly & drafe ***\n\n Man:\n\
	\t< > v ^ : Rotation\n\t\tW A S D : Move\n\t\t+ - : Altitude\n\
	\tC : Color\n\t\tESC - Quit\n");
	fd = fdf_open(argv[1]);
	new_w.p = all_ps;
	p_nb = fdf_read(fd, &new_w);
	//while(i < new_w.p_nb)
	//{
	///	fdf_p_struct(new_w.p, i);
	//	i++;
	//}
	fdf_new_win(&new_w, p_nb, argv[1]);
	fdf_draw(&new_w);
	close(fd);
	exit(0);
}
