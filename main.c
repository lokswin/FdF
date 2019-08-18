/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/08/18 17:40:02 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** **************************************************************************
**	int file_to_arr(char *s, int i)
**	Function to store coords
**	//printf("buff[%d]=%s", x-1, buff[x-1]);
**	//printf("\nbuff[0]=%s tmp_z=%d one_line[i].x=%d i=%d x=%d\n",buff[0], tmp_z[x], one_line[i].x, i, x);
**	while //printf("buff[%d]=%s, tmp_z[%d]= %d", x, buff[x], x, tmp_z[x]);
** **************************************************************************
*/

static int			file_to_arr(t_crds all_ps[260000], char *s, int p_nb, int y)
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
		all_ps[p_nb].next = &all_ps[p_nb + 1];
		all_ps[p_nb].x = 30 * i;
		all_ps[p_nb].y = 30 * y;
		all_ps[p_nb].z = ft_atoi(buff_splt[i]);
		//fdf_rotate_xy(&all_ps[p_nb].x, &all_ps[p_nb].y, all_ps[p_nb].z, 3);
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

static int		fdf_read(t_crds all_ps[260000], int fd)
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
		if (!(buff = (char*)malloc(sizeof(char) * 260000)))
		{
			ft_putstr_fd("fdf_read malloc error", 2);
			exit(1);
		}
		if ((gnl_res = ft_get_next_line(fd, &buff)) && (gnl_res == -1))
		{
			ft_putstr_fd("GNL read error", 2);
			ft_strdel(&buff);
			exit(1);
		}
		p_nb = file_to_arr(all_ps, buff, p_nb, y++);
		ft_strdel(&buff);
	}
	all_ps[p_nb - 1].next = NULL;
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
	int			p_nb;
	int			fd;

	fd = 0;
	p_nb = 0;
	if (argc != 2 || (argv[1] == NULL))
	{
		ft_putstr("usage: ./fdf source_file\n");
		exit(1);
	}
	fd = fdf_open(argv[1]);
	p_nb = fdf_read(all_ps, fd);
	fdf_draw(all_ps, p_nb, argv[1]);
	close(fd);
	exit(0);
}
