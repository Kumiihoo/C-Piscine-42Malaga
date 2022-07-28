/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:40:51 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/25 20:47:03 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argsc, char **argsv)
{
	int	j;
	int	i;

	(void) argsc;
	i = 1;
	j = 0;
	while (i < argsc)
	{
		j = 0;
		while (argsv[i][j] != '\0')
		{
			write(1, &argsv[i][j], 1);
			j++;
			if (argsv[i][j] == '\0')
			{
				write(1, "\n", 1);
			}
		}
		i++;
	}
}
