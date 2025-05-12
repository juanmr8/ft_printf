/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:28:17 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/12 17:00:07 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_args(char format, va_list *ap)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(*ap, int), "0123456789", 0));
	else if (format == 'u')
		return (ft_putnbr_base_unsigned(va_arg(*ap, unsigned int),
				"0123456789", 0));
	else if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'p')
		return (ft_print_pointer(va_arg(*ap, void *)));
	else if (format == 'x')
		return (ft_putnbr_base_unsigned(
				va_arg(*ap, unsigned int), "0123456789abcdef", 0));
	else if (format == 'X')
		return (ft_putnbr_base_unsigned(
				va_arg(*ap, unsigned int), "0123456789ABCDEF", 0));
	return (0);
}

int	ft_printf(char const *input, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, input);
	i = 0;
	count = 0;
	if (!input)
		return (0);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			count = count + print_args(input[i], &ap);
			i++;
		}
		else
		{
			count += ft_putchar(input[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}

/*int	main(void)
{
	int count = ft_printf("my printf: %c %c %c \n", '1', '2', '3');
	int	realCount = printf("real printf: %c %c %c \n", '1', '2', '3');

	return (0);
}*/
