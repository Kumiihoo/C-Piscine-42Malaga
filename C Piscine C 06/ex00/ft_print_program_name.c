/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:48:22 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/25 20:41:58 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argsc, char **argsv)
{
	int	j;

	(void) argsc;
	(void) argsv;
	j = 0;
	while (argsv[0][j] != '\0')
	{
		write(1, &argsv[0][j], 1);
		j++;
	}
	write(1, "\n", 1);
}
