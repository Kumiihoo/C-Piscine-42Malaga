/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedina <mamedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:54:51 by mamedina          #+#    #+#             */
/*   Updated: 2022/07/14 23:06:16 by mamedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_print_combn(int n)
{
    while (n > 0 && n < 10)
    {
        /* code */
    }
    
}

int main (void)
{
    ft_print_combn();
    return(0);
}
