/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:10:49 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 13:47:44 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Validates a line within a configuration file based
 *        on its position and content.
 *
 * This function determines if a specific line in a configuration file
 * is valid for its designated position. Validation criteria vary depending on
 * the line's position, using other helper functions for specific checks:
 *
 * - Positions 1-4: Expected to be texture specifications.
 * - Positions 5-6: Expected to be color specifications.
 * - Positions > 6: Assumed to be part of the map data.
 *
 * If all checks pass, the function returns `TRUE`. 
 * Otherwise, it returns `FALSE` 
 *
 * @param position The integer representing the line's position.
 * @param line Pointer to a null-terminated character string 
 *             containing the line to be validated.
 * @param n_lines The total number of lines in the configuration file.
 *
 * @return `TRUE` if the line is valid for its position, `FALSE` otherwise.
 */
int	ft_is_valid_line(int position, const char *line, int n_lines)
{
	if (position == 1 && ft_is_valid_texture_line("NO", line) == FALSE)
		return (FALSE);
	if (position == 2 && ft_is_valid_texture_line("SO", line) == FALSE)
		return (FALSE);
	if (position == 3 && ft_is_valid_texture_line("WE", line) == FALSE)
		return (FALSE);
	if (position == 4 && ft_is_valid_texture_line("EA", line) == FALSE)
		return (FALSE);
	if (position == 5 && ft_is_color_line("F", line) == FALSE)
		return (FALSE);
	if (position == 6 && ft_is_color_line("C", line) == FALSE)
		return (FALSE);
	if (position > 6 && ft_is_valid_map_line(position, line, n_lines) == FALSE)
		return (FALSE);
	return (TRUE);
}
