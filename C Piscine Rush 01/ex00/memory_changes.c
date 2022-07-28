/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_changes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ar <mruiz-ar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:32:43 by mruiz-ar          #+#    #+#             */
/*   Updated: 2022/07/17 15:56:58 by mruiz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
Lógica:
1) Reservamos el espacio de memoria -> malloc
	Necesitamos una matriz de 4x4 espacios de memoria
	· Reservamos 'res': son los punteros de las filas
	· Reservamos 'res[index]': son los punteros de las posiciones en filas
2) Vamos revisando que la memoria no estuviese llena
	Si res == NULL -> return (NULL) para evitar punteros a nulo
3) Conforme se crea, rellenamos cada posición con los argumentos:
			res[index][subindex] = str[charindex] - '0';
	· Le restamos - '0' para transformar char a int

Variables:
· *str: string que nos pasan por consola
· index: filas de la matriz
· subindex: columnas de la matriz (posiciones en cada fila)
· charindex: posiciones dentro del string
· **res: matriz que nos reserva memoria y se rellena con argumentos
*/
int	**ft_mem_args(char *str, int index, int subindex, int charindex)
{
	int	**res;

	res = (int **)malloc(4 * sizeof(int *));
	if (res == NULL)
		return (NULL);
	while (index < 4)
	{
		res[index] = (int *)malloc(4 * sizeof(int));
		if (res == NULL)
			return (NULL);
		subindex = 0;
		while (subindex < 4)
		{
			if (charindex % 2 == 0)
			{
				res[index][subindex] = str[charindex] - '0';
				subindex++;
			}
			charindex++;
		}
		index++;
	}
	return (res);
}

/*
Variables:
· **mem_matrix: matriz que se crea con los espacios de memoria reservados
· *aux: posiciones dentro de las filas de la matriz reservadas
· index: 
*/
int	**ft_save_mem(void)
{
	int	**mem_matrix;
	int	index;

	index = 0;
	mem_matrix = (int **)malloc(4 * sizeof(int *));
	if (mem_matrix == NULL)
		return (NULL);
	while (index < 4)
	{
		mem_matrix[index] = (int *)malloc(4 * sizeof(int));
		if (mem_matrix == NULL)
			return (NULL);
		index++;
	}
	return (mem_matrix);
}

/*
Liberamos el espacio de memoria que ocupaba la matriz con función 'free':
	1) Recorremos punteros de posiciones de filas 
	2) Recorremos punteros de las propias filas

Se usa para liberar: 
· given_views
· matrix_sol

Por parámetros pasamos la tabla que queremos liberar. Ej. matrix_sol
*/
void	ft_free_mem(int	**matrix)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free((matrix)[i]);
		i++;
	}
	free(matrix);
}
