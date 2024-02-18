/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:15:28 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 14:33:14 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_is_valid_map_line(int position, const char *line, int nlines)
{
	if (position == 7 && ft_is_valid_first_map_line(line) == FALSE)
		return (ft_show_error("Invalid first map line.\n"));
	if (position > 7 && position < nlines && \
						ft_is_valid_inter_map_line(line) == FALSE)
		return (ft_show_error("Invalid first map line.\n"));
	if (position == nlines && ft_is_valid_last_map_line(line) == FALSE)
		return (ft_show_error("Invalid first map line.\n"));
	return (TRUE);
}

int	ft_line_has_only_6(const char *str)
{
	while (*str)
	{
		if (*str != '0' && *str != 'N' && *str != 'S' && *str != 'W' \
			&& *str != 'E' && *str != '1' && *str != ' ' && *str != '\n')
		{
			return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

int	ft_line_has_only_1(const char *str)
{
	while (*str)
	{
		if (*str != '1' && *str != ' ' && *str != '\n')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	ft_is_valid_first_map_line(const char *line)
{
	char	*map_line;

	map_line = ft_strtrim(line, " ");
	if (ft_line_has_only_1(map_line) == FALSE)
		return (ft_show_error("Incorrect last line."));
	free(map_line);
	return (TRUE);
}

int	ft_is_valid_inter_map_line(const char *line)
{
	char	*map_line;

	map_line = ft_strtrim(line, " ");
	if (ft_line_has_only_6(map_line) == FALSE)
		return (ft_show_error("Incorrect map line."));
	if (map_line[0] != '1')
		return (ft_show_error("Open map line."));
	if (map_line[ft_strlen(map_line)-2] != '1')
		return (ft_show_error("Open map line."));
	free(map_line);
	return (TRUE);
}

int	ft_is_valid_last_map_line(const char *line)
{
	char	*map_line;

	map_line = ft_strtrim(line, " ");
	if (ft_line_has_only_1(map_line) == FALSE)
		return (ft_show_error("Incorrect last line."));
	free(map_line);
	return (TRUE);
}
