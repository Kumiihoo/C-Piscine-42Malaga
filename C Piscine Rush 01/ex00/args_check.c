/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ar <mruiz-ar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:52:40 by mruiz-ar          #+#    #+#             */
/*   Updated: 2022/07/17 15:55:54 by mruiz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ft_mem_args(char *str, int index, int subindex, int charindex);

/*
Recorremos el string de argumentos checkeando su longitud:
· Sumamos 1 hasta llegar a '\0'
· La longitud debe ser 31 (16 dígitos y 15 espacios)

Variables:
· str_length: longitud del string
*/
static int	ft_check_len(char	*str)
{
	int	str_length;

	str_length = 0;
	while (str[str_length] != '\0')
	{
		str_length++;
	}
	return (str_length);
}

/*
Recorremos el string de argumentos checkeando si:
· Pares = dígitos
· Impares = espacios
Si no se cumple -> return (0)
Si se cumple -> retornamos a ft_mem_args y asignamos nueva memoria

Variables:
· x: posición en el string
*/
static int	ft_arg_format(char	*str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (x % 2 == 0 && (str[x] < '1' || str[x] > '4'))
			return (0);
		if (x % 2 == 1 && str[x] != ' ')
			return (0);
		x++;
	}
	return (1);
}

/*
Comprobamos que los argumentos que nos pasan por consola son válidos:
· Deben ser 2 argumentos (argc = 2)
· La longitud del string debe ser 31 (ft_check_len = 31)
· Cumple con el formato dígito-espacio-digito-espacio... (ft_arg_format = 1)
Si no se cumple -> return (NULL)
Si se cumple -> retornamos a ft_mem_args y asignamos nueva memoria

Variables:
· argc: nº de argumentos
· argv[1]: string de argumentos que nos pasan por consola
*/
int	**ft_check_args(int argc, char **argv)
{
	if (argc != 2 || ft_check_len(argv[1]) != 31 || !ft_arg_format(argv[1]))
		return (NULL);
	else
		return (ft_mem_args(argv[1], 0, 0, 0));
}
