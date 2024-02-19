/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:06:34 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 14:57:02 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_check_lines(const char *filename, int nlines);
static int	ft_count_directions(const char *line, char caracter);

/**
 * Checks if a given file contains a valid map representation.
 *
 * @param filename  The name of the file to check.
 * @return          TRUE if the file is a valid map, FALSE otherwise.
 *
 *  - Validates that the file has at least 9 lines.
 *  - Calls `ft_check_files` to perform more detailed checks.
 *  - Returns FALSE and displays an error message if the file is invalid.
 */
int	ft_is_valid_map(const char *filename)
{
	int	nlines;

	nlines = ft_count_files(filename);
	if (nlines < 9)
		return (ft_show_error("Less than 9 lines in file"));
	if (ft_check_lines(filename, nlines) == FALSE)
		return (FALSE);
	return (TRUE);
}

/**
 * Checks the individual lines of a file to ensure they meet map requirements.
 *
 * @param filename  The name of the file to check.
 * @param nlines    The number of lines in the file.
 * @return          TRUE if all lines are valid, FALSE otherwise.
 *
 *  - Opens the file in read-only mode.
 *  - Iterates through each line of the file:
 *      - Skips lines that only contain spaces.
 *      - Calls `ft_is_valid_line` to check if the line is valid.
 *      - Returns FALSE and closes the file if an invalid line is encountered.
 *  - Returns TRUE if all lines are valid.
 */
static int	ft_check_lines(const char *filename, int nlines)
{
	char	*line;
	int		fd;
	int		pos;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_show_error("Error.\n File not opening");
	pos = 1;
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		if (ft_line_all_spaces(line) == FALSE)
		{
			if (ft_is_valid_line(pos++, line, nlines) == FALSE)
			{
				close(fd);
				free(line);
				return (FALSE);
			}
			if (pos > 6)
			{
				count += ft_count_directions(line, 'N');
				count += ft_count_directions(line, 'S');
				count += ft_count_directions(line, 'W');
				count += ft_count_directions(line, 'E');
			}
		}
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	if (count > 1)
		return (ft_show_error("Too many spawn points."));
	return (TRUE);
}

static int	ft_count_directions(const char *line, char caracter)
{
	int	contador;
	int	i;

	i = 0;
	contador = 0;
	while (line[i] != '\0')
	{
		if (line[i++] == caracter)
		{
			contador++;
		}
	}
	return (contador);
}
