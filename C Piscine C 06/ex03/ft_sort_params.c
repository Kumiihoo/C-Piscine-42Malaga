/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:40:34 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/26 17:01:12 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			return (res);
		}
		i++;
	}
	return (res);
}

void	ft_wstr(int argsc, char **argsv)
{
	int	i;
	int	j;

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

int	main(int argsc, char **argsv)
{
	int		j;
	int		i;
	char	*aux;

	i = 1;
	while (i < argsc - 1)
	{
		j = 0;
		while (j <= argsc - i - 1)
		{
			if (ft_strcmp(argsv[j], argsv[j + 1]) > 0)
			{
				aux = argsv[j];
				argsv[j] = argsv[j + 1];
				argsv[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
	ft_wstr(argsc, argsv);
}
