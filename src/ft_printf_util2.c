/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:42:19 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/27 20:18:15 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}

int	ft_printf_putxnbr(unsigned int unbr, char *base)
{
	int	len;

	len = 0;
	if (unbr >= ft_strlen(base))
		len += ft_printf_putxnbr(unbr / ft_strlen(base), base);
	len += ft_printf_putchar(base[unbr % ft_strlen(base)]);
	return (len);
}

int	ft_printf_puthex(int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[n], 1);
	return (1);
}

int	ft_printf_putmemory(unsigned long long addr)
{
	int	len;

	len = 0;
	if (addr >= 16)
		len += ft_printf_putmemory(addr / 16);
	else
		len += ft_printf_putstr("0x");
	len += ft_printf_puthex(addr % 16);
	return (len);
}
