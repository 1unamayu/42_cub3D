/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_map_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:10:42 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 14:08:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

/**
 * Counts the number of valid map lines in a file.
 *
 * @param filename The path to the map file.
 *
 * @return The number of lines in the file containing valid map elements
 *         ('1' or '0'), or -1 on error.
 *
 * This function counts the number of lines in the map file specified by
 * `filename` that represent valid map elements. A valid map line starts with
 * either the character '1' or '0', representing a wall or empty space,
 * respectively. Empty lines and lines starting with other characters are
 * ignored.
 *
 */
int	ft_count_map_lines(char *filename)
{
	char	*line;
	int		fd;
	int		count;
	char	*lineclear;

	count = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		lineclear = ft_strtrim(line, " ");
		if (lineclear[0] == '1' || lineclear[0] == '0')
			count ++;
		free(line);
		free(lineclear);
		line = get_next_line(fd);
	}
	return (count);
}
