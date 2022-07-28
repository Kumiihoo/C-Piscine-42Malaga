/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:42:08 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/20 19:58:05 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		else
		{
			if (!(str[i - 1] >= 65 && str[i - 1] <= 90)
				&& !(str[i - 1] >= 97 && str[i - 1] <= 122)
				&& !(str[i - 1] >= 48 && str[i - 1] <= 57))
			{
				if (str[i] >= 97 && str[i] <= 122)
					str[i] = str[i] - 32;
			}
			else
			{
				if (str[i] >= 65 && str[i] <= 90)
					str[i] = str[i] + 32;
			}
		}
		i++;
	}
	return (str);
}
