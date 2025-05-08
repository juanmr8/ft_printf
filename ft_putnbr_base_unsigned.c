/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:34:38 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/08 07:46:56 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
/* Print number of n base and unsigned */
int ft_putnbr_base_unsigned(unsigned int nbr, char *base, int count)
{
    unsigned int base_value;

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
