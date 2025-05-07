/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:28:17 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/07 13:26:36 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

/* Imprimir en el formato indicado */
static int	ft_print_args(char format, va_list ap)
{
	
}

/* Process arguments from the main printf function, also print non-formatted chars */
static int	ft_process_args(char *arg, va_list ap)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '%')
		{
			count += ft_print_args(arg[i + 1], ap);
			i++;
		}
		else {
			write(1, arg[i], 1);
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
	write(1, "Hello", 5);
	return (0);
}