/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:22:18 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/05/12 17:31:58 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(int nbr, char *base, int count);
void	ft_putnbr(int nb);
int		ft_check_base(char *base);
int		ft_putnbr_base_unsigned(unsigned long nbr, char *base, int count);
int		ft_print_pointer(void *ptr);

#endif
