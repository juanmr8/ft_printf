/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:25:49 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/07 18:47:35 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_check_base(char *base)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(base);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = -1;
	while (i++ < len - 1)
	{
		j = i + 1;
		while (base[i] != base[j] && j < len - 1)
			j++;
		if (base[i] == base[j])
			return (0);
	}
	return (1);
}

int	ft_putnbr_base(int nbr, char *base, int count)
{
	int	base_value;

	base_value = ft_strlen(base);
	if (ft_check_base(base) == 0 || base_value < 2)
	{
		return (count);
	}
	if (nbr == -2147483647)
	{
		ft_putstr("-2147483647");
		return (count);
	}
	if (nbr < 0)
	{
		ft_putstr("-");
		nbr = -nbr;
	}
	if (nbr > base_value)
		count = ft_putnbr_base(nbr / base_value, base, count);
	count += write(1, &base[nbr % base_value], 1);
	return (count);
}
/*int	main(void)
{
	ft_put_nbr_base(42324, "0123456789");
	return (0);
}*/
