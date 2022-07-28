/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:32:42 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/14 17:49:11 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_comb2(void);
void	ft_putchar(char n_1, char n_2, char n_3, char n_4);

void	ft_putchar(char n_1, char n_2, char n_3, char n_4)
{
	write(1, &n_1, 1);
	write(1, &n_2, 1);
	write(1, " ", 1);
	write(1, &n_3, 1);
	write(1, &n_4, 1);
	if (n_2 < '8' || n_1 < '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_reset(char *sum, char *reset)
{
	if (*reset == '9')
	{
		*sum += 1;
		*reset = '0';
	}
	else
	{
		*reset += 1;
	}
}

void	ft_print_comb2(void)
{
	char	n_1;
	char	n_2;
	char	n_3;
	char	n_4;

	n_1 = '0';
	n_2 = '0';
	n_3 = '0';
	n_4 = '1';
	while (n_1 <= '9' && n_2 <= '9')
	{
		n_3 = n_1;
		n_4 = n_2;
		ft_reset(&n_3, &n_4);
		while (n_3 <= '9' && n_4 <= '9')
		{
			ft_putchar(n_1, n_2, n_3, n_4);
			ft_reset(&n_3, &n_4);
		}
		ft_reset(&n_1, &n_2);
	}
}
