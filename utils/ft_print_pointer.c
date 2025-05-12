/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:48:29 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/12 16:57:05 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr("0x0");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_base_unsigned((unsigned long)ptr, "0123456789abcdef", 0);
	return (count);
}
