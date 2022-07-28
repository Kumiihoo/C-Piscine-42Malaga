/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbsq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dllanes- <dllanes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:15:44 by dllanes-          #+#    #+#             */
/*   Updated: 2022/07/27 19:57:52 by dllanes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define RED "\x1B[31m"
#define BLUE "\x1b[34m"
#define MAGEN "\x1b[45m"

int	main(void)
{
	write(1, "Buenas, se buscaba realizar un mapa como este:\n", 48);
	write(1, "...........................\n", 29);
	write(1, "......^...........^........\n", 29);
	write(1, "...../.|........./.|.......\n", 29);
	write(1, "..../...|......./...|......\n", 29);
	write(1, "...........................\n", 29);
	write(1, ".......____________........\n", 29);
	write(1, ".......|..........|........\n", 29);
	write(1, "........__________.........\n", 29);
	write(1, "...........................\n", 29);
	write(1, RED "Vaya... Bueno, pase un buen día.\n", 41);
	write(1, BLUE "Modifique el mapa como desee.\n", 41);
	write(1, MAGEN "Y recuerda mi rey/na/ne, este mes ha sido increible.", 58);
	return (0);
}
