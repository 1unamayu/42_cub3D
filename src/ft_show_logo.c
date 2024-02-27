/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_logo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:10:04 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/23 19:25:24 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * Displays the game logo in the console.
 * 
 * This function prints a stylized logo in the console
 * using ANSI escape sequences to color the output. 
 * It also includes the credits of the game developers.
 */
void	ft_show_logo(void)
{
	printf(""KBLU"  ______  __    __ _______   ");
	printf(KMAG" ______  _______  \n");
	printf(KBLU" /      \\/  |  /  /       \\");
	printf(KMAG"/      \\/       \\ \n");
	printf(KBLU"/$$$$$$  $$ |  $$ $$$$$$$ ");
	printf(KMAG"/$$$$$$  $$$$$$$  |\n");
	printf(KBLU"$$ |  $$/$$ |  $$ $$ |__$$");
	printf(KMAG"$$ ___$$ $$ |  $$ |\n");
	printf(KBLU"$$ |     $$ |  $$ $$    $$<");
	printf(KMAG"/    $$<$$ |  $$ |\n");
	printf(KBLU"$$ |   __$$ |  $$ $$$$$$$  ");
	printf(KMAG"_$$$$$  $$ |  $$ |\n");
	printf(KBLU"$$ \\__/  $$ \\__$$ $$ |__$$ ");
	printf(KMAG"/ \\__$$ $$ |__$$ |\n");
	printf(KBLU"$$    $$/$$    $$/$$    $$/");
	printf(KMAG"$$   $$/$$    $$/ \n");
	printf(KBLU" $$$$$$/  $$$$$$/ $$$$$$$/ ");
	printf(KMAG"$$$$$$/ $$$$$$$/\n");
	printf(KYEL"@Unai Amayuelas "KGRN"\t(A.K.A xamayuel)\n");
	printf(KYEL"@Javier García Arango "KGRN"\t(A.K.A javigarc)\n"KWHT);
}
