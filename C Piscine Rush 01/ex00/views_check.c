/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ar <mruiz-ar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:36:51 by mruiz-ar          #+#    #+#             */
/*   Updated: 2022/07/17 15:48:34 by mruiz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Empezamos en la fila 0 (i=0), recorremos para abajo
· Guardamos temporalmente el valor de la posición en la tabla
	Este valor se va actualizando conforme el número incrementa
· Cuando el valor de temp es inferior a la posición actual de la tabla
	quiere decir que podemos ver el cubo siguiente, así que incrementamos el 
	num_viewed y actualizamos temp

Variables:
· temp: guarda el valor de la posición inicial de la tabla y luego se 
	incrementa conforme tenemos otra 'vista'
· num_viewed: número de cubos que vemos
*/
static int	ft_view_updown(int i, int j, int **matrix_sol)
{
	int	temp;
	int	num_viewed;

	temp = matrix_sol[i][j];
	num_viewed = 1;
	i = 0;
	while (i < 4)
	{
		if (temp < matrix_sol[i][j])
		{
			num_viewed++;
			temp = matrix_sol[i][j];
		}
		i++;
	}
	return (num_viewed);
}

/*
Empezamos en la fila 3 (i=3), recorremos para arriba
*/
static int	ft_view_downup(int i, int j, int **matrix_sol)
{
	int	temp;
	int	num_viewed;

	i = 3;
	temp = matrix_sol[i][j];
	num_viewed = 1;
	while (i >= 0)
	{
		if (temp < matrix_sol[i][j])
		{
			num_viewed++;
			temp = matrix_sol[i][j];
		}
		i--;
	}
	return (num_viewed);
}

/*
Cambiamos filas por columnas (i=j)
Empezamos en la columna 0 (j=0), recorremos para derecha
*/
static int	ft_view_leftright(int i, int j, int **matrix_sol)
{
	int	temp;
	int	num_viewed;

	i = j;
	j = 0;
	temp = matrix_sol[i][j];
	num_viewed = 1;
	while (j < 4)
	{
		if (temp < matrix_sol[i][j])
		{
			num_viewed++;
			temp = matrix_sol[i][j];
		}
		j++;
	}
	return (num_viewed);
}

/*
Cambiamos filas por columnas (i=j)
Empezamos en la columna 3 (j=3), recorremos para derecha
*/
static int	ft_view_rightleft(int i, int j, int **matrix_sol)
{
	int	temp;
	int	num_viewed;

	i = j;
	j = 3;
	temp = matrix_sol[i][j];
	num_viewed = 1;
	while (j >= 0)
	{
		if (temp < matrix_sol[i][j])
		{
			num_viewed++;
			temp = matrix_sol[i][j];
		}
		j--;
	}
	return (num_viewed);
}

/*
Vamos a comprobar desde las distintas vistas si cumple los requisitos.
0 -> vista desde arriba hacia abajo (recorremos fila++ en las columnas)
1 -> vista desde abajo hacia arriba (recorremos fila-- en las columnas)
2 -> vista desde izquierda a derecha (recorremos columna++ en las filas)
3 -> vista desde derecha a izquierda (recorremos columna-- en las filas)

					  0
					2   3
					  1
*/
int	ft_check_views(int direction, int i, int j, int **matrix_sol)
{
	int	num_viewed;

	if (direction == 0)
	{
		num_viewed = ft_view_updown(i, j, matrix_sol);
	}
	else if (direction == 1)
	{
		num_viewed = ft_view_downup(i, j, matrix_sol);
	}
	else if (direction == 2)
	{
		num_viewed = ft_view_leftright(i, j, matrix_sol);
	}
	else
	{
		num_viewed = ft_view_rightleft(i, j, matrix_sol);
	}
	return (num_viewed);
}
