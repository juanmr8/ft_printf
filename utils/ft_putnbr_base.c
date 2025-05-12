/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:25:49 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/12 17:33:00 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_check_base(char *base)
{
	int	i;
	int	j;
	int	len;

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
	long		base_value;
	long long	num;

	base_value = ft_strlen(base);
	if (ft_check_base(base) == 0 || base_value < 2)
		return (count);
	num = (long long)nbr;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	if (num >= base_value)
		count = ft_putnbr_base(num / base_value, base, count);
	count += write(1, &base[num % base_value], 1);
	return (count);
}
