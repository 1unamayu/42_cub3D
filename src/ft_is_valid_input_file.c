/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_input_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:56:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 14:05:17 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"


/**
 * @brief Checks the validity of program arguments.
 *
 * This function verifies that the provided arguments comply with the program's
 * expectations. It performs two checks:
 *
 * 1. **File extension:** Ensures the provided filename (second argument)
 *    has the correct ".cub" extension.
 * 2. **Filename existence:** Confirms that the specified filename is a valid
 *    and readable file.
 *
 * If either of these checks fails, the function returns `FALSE`. Otherwise,
 * it returns `TRUE`, indicating valid arguments.
 *
 * @param arguments Array of program arguments.
 *
 * @return `TRUE` if arguments are valid, `FALSE` otherwise.
 */

int	ft_is_valid_file_extension(const char *filename, const char *extension);
int	ft_is_valid_input_file(char *arguments[])
{
	if (ft_is_valid_file_extension(arguments[1], ".cub") == FALSE)
		return (FALSE);
	if (ft_is_valid_filename(arguments[1]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_is_valid_file_extension(const char *filename, const char *extension)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		printf("\x1B[31mERROR\n"KWHT"CUBE3D: Map filename too short."KNRM"\n");
		return (FALSE);
	}
	if (ft_strncmp(filename + len - 4, extension, 4) == 0)
		return (TRUE);
	printf(KRED"ERROR\n"KWHT"CUBE3D: Incorrect filename extension."KNRM"\n");
	return (FALSE);
}