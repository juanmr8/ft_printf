/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:28:17 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/07 19:14:56 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lib.h"


static int ft_unsigned_num(int n)
{
	unsigned int result;

	if (n < 0)
		result = UINT_MAX - n;
	else
		result = n;
	return (result);
}

static int ft_putstr(char *str)
{
	int	count;

	count = ft_strlen(str);
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
	return (count);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

/* Imprimir en el formato indicado */
static int	ft_print_args(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char*)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789", 0));
	else if (format == 'u')
    	return (ft_putnbr_base_unsigned(va_arg(ap, unsigned int), "0123456789", 0));


}

/* Process arguments from the main printf function, also print non-formatted chars */
static int	ft_process_args(const char *arg, va_list ap)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '%')
		{
			i++;
			count += ft_print_args(arg[i], ap);
			i++;
		}
		else {
			ft_putchar(arg[i]);
			count++;
			i++;
		}
	}
	return (count);
}


int	ft_printf(char const *arg, ...)
{
	int	return_value;
	va_list	ap;
	int count;

	va_start(ap, arg);
	count = ft_process_args(arg, ap);
	va_end(ap);
	return count;
}

int	main(void)
{
	int count = ft_printf("Print %s %d %u\n", "hola", 4, -2);
	int	realCount = printf("Print %s %d %u\n", "hola", 4, -2);
	ft_printf("Cuenta con mi printf %d\n", count);
	printf("Cuenta con el printf off %d\n", realCount);
	return (0);
}
