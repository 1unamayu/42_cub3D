/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:30:11 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/30 15:49:52 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_countcols(const char *str, char c)
{
	int	i;
	int	newcol;

	i = 0;
	newcol = 0;
	if (str == 0)
		return (0);
	while (*str)
	{
		if (*str != c && newcol == 0)
		{
			newcol = 1;
			i++;
		}
		else if (*str == c)
		{
			newcol = 0;
		}
		str++;
	}
	return (i);
}

t_coord	ft_rows_cols_check(int fd)
{
	int		rows;
	int		colscheck;
	t_coord	coords;
	char	*line;

	rows = 0;
	line = get_next_line(fd);
	colscheck = ft_countcols(line, ' ');
	while (line)
	{
		rows++;
		if (colscheck != ft_countcols(line, ' '))
		{
			ft_putstr_fd("Error. Bad formatted map.\n", 1);
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
	}
	coords.rowx = rows;
	coords.coly = colscheck;
	free(line);
	return (coords);
}

void	ft_print_map(t_map maptoprint, int rows, int cols)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			ft_putnbr_fd(maptoprint.mapdots[x][y].hz, 1);
			ft_putstr_fd("  ", 1);
			y++;
		}
		ft_putstr_fd("\n", 1);
		x++;
	}
}

t_map	ft_read_map(char *namefile)
{
	t_map	maptoload;
	int		fd;

	fd = open(namefile, O_RDWR);
	if (fd > 0)
	{
		maptoload.rowscols = ft_rows_cols_check(fd);
		close(fd);
		fd = open(namefile, O_RDWR);
		maptoload.mapdots = ft_load_mapdots(fd, maptoload.rowscols.rowx, \
				maptoload.rowscols.coly);
		close(fd);
	}
	else
	{
		ft_putstr_fd("Error. Invalid file.\n", 2);
		exit(1);
	}
	if ((!maptoload.rowscols.rowx) || (!maptoload.rowscols.coly))
	{
		ft_putstr_fd("Error. Incorrect map file.\n", 2);
		exit(1);
	}
	return (maptoload);
}

t_dot	**ft_load_mapdots(int fd, int rows, int cols)
{
	t_maplines	ml;

	ml.x = -1;
	ml.dotstoload = (t_dot **) malloc(sizeof (t_dot *) * rows);
	if (!ml.dotstoload)
		exit(1);
	while (++ml.x < rows)
	{
		ml.dotstoload[ml.x] = (t_dot *) malloc(sizeof (t_dot) * cols);
		if (!ml.dotstoload[ml.x])
			exit(1);
		ml.line = get_next_line(fd);
		ml.lines = ft_split(ml.line, ' ');
		ml.y = -1;
		while (++ml.y < cols)
		{
			ml.dotstoload[ml.x][ml.y].hz = ft_atoi(ml.lines[ml.y]);
			ml.dotstoload[ml.x][ml.y].dotcolor = DEF_CLR;
			free(ml.lines[ml.y]);
		}
		free (ml.lines);
		free (ml.line);
		ml.line = NULL;
	}
	return (ml.dotstoload);
}
