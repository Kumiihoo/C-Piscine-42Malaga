/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:14:15 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/27 18:08:54 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	sol;

	sol = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power < 0)
		return (0);
	while (power >= 1)
	{
		sol *= nb;
		power--;
	}
	return (sol);
}
