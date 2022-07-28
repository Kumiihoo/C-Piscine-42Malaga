/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ar <mruiz-ar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:49:28 by mruiz-ar          #+#    #+#             */
/*   Updated: 2022/07/17 15:50:27 by mruiz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Recorremos el string pasado por parámetros ("Error\n") y lo imprimimos
*/
void	ft_print_error(char	*c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
}

/*
Imprimimos la solución verdadera
*/
void	ft_print_sol(int **sol)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = sol[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
