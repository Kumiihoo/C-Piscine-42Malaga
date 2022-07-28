/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:26:22 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/21 13:08:47 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_length(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;

	j = 0;
	if (size != 0)
	{
		while (src[j] != '\0' && j < size - 1)
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (ft_length(src));
}
