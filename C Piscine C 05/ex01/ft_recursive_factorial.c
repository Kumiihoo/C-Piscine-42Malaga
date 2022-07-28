/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:25:06 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/27 13:52:39 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
	{
		return (0);
	}
	else if (nb > 1)
	{
		res = nb * ft_recursive_factorial(nb - 1);
	}
	return (res);
}
