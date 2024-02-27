/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pantalla.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:27 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 11:37:05 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_print_pantalla(char **pantalla, int rows)
{
	int	i;
	int	j;

	ft_show_parse_error("Open map.");
	printf("\n");
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < (int)ft_strlen(pantalla[i]))
		{
			if (pantalla[i][j] == 'C')
				printf("\x1B[31m%s", "▓");
			else if (pantalla[i][j] == '1')
				printf("\x1B[36m%s", "█");
			else
				printf("%c", pantalla[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}
