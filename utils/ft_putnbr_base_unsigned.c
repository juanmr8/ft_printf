/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:34:38 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/12 16:47:31 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_base_unsigned(unsigned long nbr, char *base, int count)
{
	unsigned long	base_value;

	base_value = ft_strlen(base);
	if (ft_check_base(base) == 0 || base_value < 2)
	{
		return (count);
	}
	if (nbr >= base_value)
		count = ft_putnbr_base_unsigned(nbr / base_value, base, count);
	count += ft_putchar(base[nbr % base_value]);
	return (count);
}
