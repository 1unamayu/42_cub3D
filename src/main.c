/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 15:52:07 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parser.h"
#include "game_struct.h"

t_data* init_data()
{
   
   t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	data->map2d = ft_calloc(10, sizeof(char *)); // init the map
	data->map2d[0] = strdup("1111111111111111111111111"); //fill the map
	data->map2d[1] = strdup("1000000000000000000100001");
	data->map2d[2] = strdup("1001000000000N00000000001");
	data->map2d[3] = strdup("1001000000000000001000001");
	data->map2d[4] = strdup("1001000000000000001000001");
	data->map2d[5] = strdup("1001000000100000001000001");
	data->map2d[6] = strdup("1001000000000000001000001");
	data->map2d[7] = strdup("1001000000001000001000001");
	data->map2d[8] = strdup("1111111111111111111111111");
	data->map2d[9] = NULL;

	data->c_celing.r = 250;
	data->c_celing.g = 0;
	data->c_celing.b = 127;

	data->c_floor.r = 250;
	data->c_floor.g = 0;
	data->c_floor.b = 127;

	data->p_x = 100;
	data->p_x = 200;

	data->w_map = 1920;
	data->h_map = 1080;

	data->t_no.texture_path = ft_strdup("textures/barrel.xpm");
	data->t_so.texture_path = ft_strdup("textures/barrel.xpm");
	data->t_we.texture_path = ft_strdup("textures/barrel.xpm");
	data->t_ea.texture_path = ft_strdup("textures/barrel.xpm");
	return (data);
}
int	main(int argn, char *argv[])
{
	t_data	*game;
	
	if (argn != 2)
	{
		printf(KRED"Error\n"KWHT"CUBE3D: Incorrect number of arguments."KNRM"\n");
		printf(KBLU"CUBE3D: Usage ./cube3d <mapfile.cub>");
				}
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		printf(KBLU"\nLoading %s ...\n",argv[1]);
		printf(KNRM);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			game = init_data();
			//game = ft_parse_map(argv[1]);
			printf("%d\n", game->c_celing.b);
			printf("%s\n", game->t_no.texture_path);
			// start_the_game(game); 
		}
	}
	exit(0);
}
