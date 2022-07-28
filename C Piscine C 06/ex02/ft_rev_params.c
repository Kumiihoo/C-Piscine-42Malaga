/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:08:32 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/25 20:35:51 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argsc, char **argsv)
{
	int	j;
	int	i;

	i = argsc - 1;
	j = 0;
	while (i < argsc && i > 0)
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
		i--;
	}
}
