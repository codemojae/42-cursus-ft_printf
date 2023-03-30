/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:41:14 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/27 21:38:39 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_putstr(char *s)
{
	size_t	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		i += ft_printf_putchar(s[i]);
	}
	return (i);
}

int	ft_printf_putnbr(int nb)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (nb < 0)
	{
		len += ft_printf_putchar('-');
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		len += ft_printf_putnbr(nbr / 10);
	len += ft_printf_putchar((char)(nbr % 10 + 48));
	return (len);
}

int	ft_printf_putunbr(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr >= 10)
		len += ft_printf_putunbr(unbr / 10);
	len += ft_printf_putchar((char)(unbr % 10 + 48));
	return (len);
}
