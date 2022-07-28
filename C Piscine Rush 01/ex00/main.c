/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ar <mruiz-ar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:14:49 by mruiz-ar          #+#    #+#             */
/*   Updated: 2022/07/17 15:56:24 by mruiz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Importamos las librerías de malloc, free y write
#include <stdlib.h>
#include <unistd.h>

int		**ft_check_args(int argc, char **argv);
int		**ft_save_mem(void);
void	ft_free_mem(int	**matrix);
int		ft_potential_sol(int **given_views, int **matrix_sol);
void	ft_print_sol(int **sol);
void	ft_print_error(char	*c);

/*
ft_check_args
	Comprobamos que los argumentos se escribieron correctamente en consola
	· Se escribieron bien -> continuamos guardando en memoria (ft_mem_args)
		- Dejamos la matriz generada guardada en la variable given_views
	· No se escribieron bien -> Error\n
ft_save_mem
	Guardamos espacio en memoria para la matriz de potenciales soluciones
	· Lo dejamos reservado en la variable matrix_sol
ft_potential_sol
	Probamos todas las potenciales soluciones para obtener la correcta
	· Llama a ft_pot_sol_rec, que se llama recursivamente a sí misma
	· Cuando obtiene una solución correcta la guarda en 'sol'
ft_print_error
	Imprimimos "Error\n" en pantalla cuando:
	· return (0) 
	· given_views == NULL
	· No se introdujeron bien los argumentos por consola
ft_print_sol
	Imprime la solución cuando se encuentra la que es válida
ft_free_mem
	Libera la memoria que se guardó previamente en matrices con malloc
*/
int	main(int argc, char **argv)
{
	int	**given_views;
	int	**matrix_sol;
	int	sol;

	given_views = ft_check_args(argc, argv);
	if (given_views == NULL)
	{
		ft_print_error("Error\n");
		return (-1);
	}
	matrix_sol = ft_save_mem();
	sol = ft_potential_sol(given_views, matrix_sol);
	if (sol)
		ft_print_sol(matrix_sol);
	else
		ft_print_error("Error\n");
	ft_free_mem (given_views);
	ft_free_mem (matrix_sol);
	return (0);
}
