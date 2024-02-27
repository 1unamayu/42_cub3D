/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:29:34 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 13:29:20 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# define VERSION "0.1.0"
/************************** FOREGROUND COLORS *********************************/
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define KBLK  "\x1B[30m"
# define KBRD  "\x1B[91m"
# define KBGRN "\x1B[92m"
# define KBYEL "\x1B[93m"
# define KBBLU "\x1B[94m"
# define KBMAG "\x1B[95m"
# define KBCYN "\x1B[96m"
# define KBWHT "\x1B[97m"
# define KNON  "\033[0m"
# define KBLA  "\x1b[40m"
/******************************************************************************/
// checks

int		ft_is_valid_map(const char *filename);
int		ft_is_valid_line(int position, const char *line, int n_lines);
int		ft_is_valid_texture_line(const char *direction, const char *line);
int		ft_is_color_line(const char *type, const char *line);
int		ft_is_valid_texture_line(const char *direction, const char *line);
int		ft_is_valid_map_line(int position, const char *line, int nlines);
int		ft_is_valid_first_map_line(const char *line);
int		ft_is_valid_inter_map_line(const char *line);
int		ft_is_valid_last_map_line(const char *line);
//utils
int		ft_is_valid_filename(const char *filename);
int		ft_count_files(const char *filename);

char	*ft_str_remove_newline(char *str);
int		ft_line_all_spaces(const char *line);
int		ft_show_error(const char *error_text);

void	ft_free_split(char **split);
#endif