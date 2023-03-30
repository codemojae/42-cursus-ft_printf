/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:46:15 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/27 21:40:39 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_onlynbr(int nb)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (nb < 0)
	{
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		len += ft_printf_putnbr(nbr / 10);
	len += ft_printf_putchar((char)(nbr % 10 + 48));
	return (len);
}

int	ft_printf_putnbr_format(int nb, char sign)
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
	{
		len += ft_printf_putchar(sign);
		nbr = (unsigned int)nb;
	}
	if (nbr >= 10)
		len += ft_printf_putnbr(nbr / 10);
	len += ft_printf_putchar((char)(nbr % 10 + 48));
	return (len);
}

int	ft_printf_zero_int(int nb, int zerosize)
{
	int	len;
	int	zerolen;

	len = 0;
	if (nb < 0)
	{
		len += ft_printf_putchar('-');
	}
	zerolen = zerosize - check_nbrlen(nb, 10);
	while (zerolen-- > 0)
		len += ft_printf_putchar('0');
	len += ft_printf_onlynbr(nb);
	return (len);
}

int	ft_printf_zero_uint(unsigned int nb, int zerosize)
{
	int	len;
	int	zerolen;

	len = 0;
	zerolen = zerosize - check_unbrlen(nb, 10);
	while (zerolen-- > 0)
		len += ft_printf_putchar('0');
	len += ft_printf_putunbr(nb);
	return (len);
}

int	ft_printf_zero_hex(unsigned int nb, int zerosize, char xsize)
{
	int	len;
	int	zerolen;

	len = 0;
	zerolen = zerosize - check_unbrlen(nb, 16);
	while (zerolen-- > 0)
		len += ft_printf_putchar('0');
	if (xsize == 'x')
		len += ft_printf_putxnbr(nb, "0123456789abcdef");
	else
		len += ft_printf_putxnbr(nb, "0123456789ABCDEF");
	return (len);
}
