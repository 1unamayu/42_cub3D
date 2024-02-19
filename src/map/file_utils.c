/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:39:09 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 13:48:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_is_valid_filename(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(KRED"Error\n"KWHT"CUBE3D");
		return (FALSE);
	}
	if (close(fd) == -1)
	{
		perror(KRED"Error\n"KWHT"CUBE3D");
		return (FALSE);
	}
	return (TRUE);
}

int	ft_count_files(const char *filename)
{
	char	*line;
	int		fd;
	int		pos;

	pos = 1;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		pos++;
	}
	close(fd);
	free(line);
	return (pos - 1);
}

char	*ft_str_remove_newline(char *str)
{
	char	*ptr;

	ptr = ft_strrchr(str, '\n');
	if (ptr != NULL)
	{
		*ptr = '\0';
	}
	return (str);
}

int	ft_line_all_spaces(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isspace(line[i++]))
			return (FALSE);
	}
	return (TRUE);
}
