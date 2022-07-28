/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:16:11 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/24 16:05:15 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	length;

	i = 0;
	j = 0;
	length = 0;
	while (dest[i] != '\0')
		i++;
	while (src[length] != '\0')
		length++;
	if (size <= i)
		length += size;
	else
		length += i;
	while (src[j] && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (length);
}
