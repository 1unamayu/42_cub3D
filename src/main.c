/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 22:57:26 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parser.h"
#include "game_struct.h"
#include "game.h"

int	main(int argn, char *argv[])
{
	t_data	*game;

	ft_show_logo();
	if (argn != 2)
	{
		printf(KRED"Error\n"KWHT"CUBE3D: Incorrect number of arguments."KNRM"\n");
		printf(KBLU"CUBE3D: Usage ./cube3d <mapfile.cub>");
				}
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		printf("DENTRO");
		printf(KBLU"\nLoading %s ...\n",argv[1]);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			printf(KGRN"Parsing %s ...\n"KNRM"", argv[1]);
			game = ft_parse_map(argv[1]);
			if (game != NULL)
			{
				ft_print(*game);
				start_the_game(game, argv[1]);
				ft_free_data(game);
			}
		}
	}
	printf("FUERA");
	exit(0);
}
