/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:54:32 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/20 11:33:44 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strchrc()
 * 
 * DESCRIPTION:
 * 		Locates the first occurrence of c(converted to a char) in the string s.
 * 		The terminating null character is considered part of string.
 * 		Counts numbers of ocurrences.
 * 
 * RETURN:
 * 		Returns the total.
 * 
 * PARAMS:
 * 		@param s: string
 * 		@param c: char to find.
 * TIP:
 * 		1. '\0' is also considered, so len + 1
 */

int	ft_strchrc(const char *s, int c)
{
	size_t	s_len;
	size_t	i;
	int		t;

	s_len = ft_strlen(s);
	i = 0;
	t = 0;
	while (i < s_len + 1)
	{
		if ((char)c == s[i])
			t++;
		i++;
	}
	return (t);
}
