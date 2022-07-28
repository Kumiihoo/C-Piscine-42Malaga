/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ar <mruiz-ar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:43:39 by mruiz-ar          #+#    #+#             */
/*   Updated: 2022/07/17 15:48:53 by mruiz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_views(int direction, int i, int j, int **matrix_sol);

/*
	Recorremos la matriz de potencial solución para comprobar si cumple las
	condiciones desde todas las vistas.

	Recibimos el número de vistas desde cada perspectiva, si no coincide con lo 
	que nos indicaron por parámetros (desde consola), no es válida y return (0)
	Si coincide, incrementamos j y seguimos el bucle hasta j < 4. 
	Cuando j >= 4, incrementamos i hasta i < 4. 
	Cuando i >= 4, salimos con return (1) -> hay solución válida y la imprimimos

	Variables:
	· i: filas 
		(lo pasamos dos veces a ft_check_views para asignarlo a != variables)
	· j: columnas
	· num_viewed: permite 'mirar' desde las distintas perspectivas y retornar
		cuántos cubos se ven desde cada una
*/
static int	ft_definitive_sol(int **given_views, int **matrix_sol)
{
	int	i;
	int	j;
	int	num_viewed;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			num_viewed = ft_check_views(i, i, j, matrix_sol);
			if (num_viewed != given_views[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
Comprobamos que el número que estamos tratando de introducir (x) no se ha
repetido:
· Hacia la izquierda en filas (while (i >= 0) {...})
· Hacia arriba en columnas (while (j >= 0) {...})

Lógica:
· Cuando entramos con i=0 y j=0:
	· i=0 pasa a ser i=-1 y no entramos en while
	· Luego reasignamos i=temp para que vuelva a ser i=0
	· j=0 pasa a ser j=-1 y no entramos en while
	· ft_num_isvalid -> return (1)
	· En ft_pot_sol_rec asignamos matrix_sol[i][j] = x (guardamos 'x' válida)
· En la siguiente vuelta entramos con i=0 y j=1:
	· i=0 pasa a ser i=-1 y no entramos en while
	· Luego reasignamos i=temp para que vuelva a ser i=0
	· j=1 pasa a ser j=0 y SÍ entramos en while
	· Comprobamos si el valor de x es igual al valor que había en la posición
		anterior de la tabla (ej. matrix_sol[0][0] == 1)
		- Si es igual -> return (0) y j=-1 y salimos de la función
			· Volvemos a entrar incrementando 1 a la x
		- Si NO es igual -> j=-1 y salimos de la función con return (1)
			· En ft_pot_sol_rec asignamos matrix_sol[i][j] = x 
				(esto es, guardamos 'x' válida)

Variables:
· temp: reservamos temporalmente el valor de i
*/
static int	ft_num_isvalid(int x, int **matrix_sol, int i, int j)
{
	int	temp;

	temp = i;
	i--;
	while (i >= 0)
	{
		if (matrix_sol[i][j] == x)
			return (0);
		i--;
	}
	i = temp;
	j--;
	while (j >= 0)
	{
		if (matrix_sol[i][j] == x)
			return (0);
		j--;
	}
	return (1);
}

/*
Si estamos en una fila superior a 3 (nos salimos de la matriz) -> return (0)
	· Quiere decir que hemos recorrido la matriz entera, sin encontrar solución
Pasamos números (x) hasta <= 4 cuando sol = 0 (aún no tenemos solución válida)
	· Sucesivamente se prueba con 1, si no con 2, si no con 3 y si no con 4
Comprobamos si es válido (no se repite para izquierda ni arriba):
	· Si es válido -> guardamos 'x' en matrix_sol[i][j] y pasamos a j++ (o i++)
	· Si no es válido, x++ y return (0) (porque sol=0)
	· Se continuan probando en todos los puntos de la matriz hasta que sol = 1

Condiciones a comprobar y qué se hace cuando es TRUE (se cumple):
· !sol -> se cumple cuando sol = 0, entonces sigue comprobando valores
· j == 3 {ft (given_views, matrix_sol, i + 1, 0)}: aumentamos fila (i) y j = 0
· else {ft (given_views, matrix_sol, i, j + 1)}: 
	aumentamos posición dentro de fila (j)
· i == 3 && j == 3 && ft_definitive_sol == 1: cuando llegamos a la posición 
	matrix_sol[3][3] y hemos encontrado una solución válida -> return (1)
		- Se asigna la solución válida a 'sol' en el main
		- Se hará la impresión de la solución con ft_print_sol 

Variables:
· given_views: matriz con los argumentos guardados (pasados por consola)
· matrix_sol: matriz de espacios de memoria para ser rellenada con soluciones
· i: filas
· j: columnas
· x: valor que estamos tratando de introducir a la matriz (probando 1, 2, 3 o 4)
	- Inicia en 1 (los números van del 1 al 4)
	- Si el 1 ya se ha escrito hacia izquierda o arriba, prueba con 2 ...
· sol: 
	- sol = 0 -> la solución no es correcta (seguimos probando valores o no hay sol)
	- sol = 1 -> la solución es correcta (entonces la enfrentamos a las vistas)
*/
static int	ft_pot_sol_rec(int **given_views, int **matrix_sol, int i, int j)
{
	int		x;
	int		sol;

	x = 1;
	sol = 0;
	if (i > 3)
		return (0);
	while (x <= 4 && !sol)
	{
		if (ft_num_isvalid(x, matrix_sol, i, j))
		{
			matrix_sol[i][j] = x;
			if (j == 3)
				sol = ft_pot_sol_rec (given_views, matrix_sol, i + 1, 0);
			else
				sol = ft_pot_sol_rec (given_views, matrix_sol, i, j + 1);
			if (i == 3 && j == 3 && ft_definitive_sol(given_views, matrix_sol))
				return (1);
		}
		x++;
	}
	return (sol);
}

/*
Pasamos las matrices creadas previamente:
· **given_views: argumentos pasados por consola (vistas)
· **matrix_sol: matriz de espacios de memoria guardada para la potencial solución
*/
int	ft_potential_sol(int **given_views, int **matrix_sol)
{
	return (ft_pot_sol_rec(given_views, matrix_sol, 0, 0));
}
