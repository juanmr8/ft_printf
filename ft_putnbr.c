/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:44:01 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/07 18:37:19 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"


static void	ft_putchar_std(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_std('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar_std((nb % 10) + '0');
}
/*int	main(void)
{
	ft_putnbr(123324123);
	ft_putnbr(213);
	ft_putnbr(-2147483648);
}*/
