/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:14:00 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/27 18:36:04 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	sol;

	sol = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power < 0)
		return (0);
	else if (power >= 1)
	{
		sol = nb * ft_recursive_power(nb, power - 1);
	}
	return (sol);
}
