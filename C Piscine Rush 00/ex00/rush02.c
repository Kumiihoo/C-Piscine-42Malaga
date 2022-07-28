/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarin-o <mmarin-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:58:24 by mmarin-o          #+#    #+#             */
/*   Updated: 2022/07/10 19:05:37 by mmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	search_print(int c_z, int c_w, int c_x, int c_y);
void	ft_putchar(char c);

int	rush(int x,	int y)
{
	int	z;
	int	w;

	z = 0;
	w = 0;
	while (w < y)
	{
		while (z < x)
		{	
			search_print (z, w, x, y);
			z++;
		}
		z = 0;
		w++;
	}
	return (0);
}

void	search_print(int c_z, int c_w, int c_x, int c_y)
{
	char	character;

	if (c_w != 0 && c_w != c_y)
		character = ' ';
	if ((c_z != 0 && c_z != c_x) && (c_w == 0 || c_w == c_y))
		character = 'B';
	if ((c_w != 0 && c_w != c_y - 1) && (c_z == 0 || c_z == c_x - 1))
		character = 'B';
	if (c_w == c_y - 1 && (c_z != 0 && c_z != c_x - 1))
		character = 'B';
	if ((c_w == c_y - 1) && (c_z == 0 || c_z == c_x - 1))
		character = 'C';
	if (c_w == 0 && (c_z == 0 || c_z == c_x - 1))
		character = 'A';
	ft_putchar(character);
	if (c_z == c_x - 1)
		ft_putchar('\n');
}
