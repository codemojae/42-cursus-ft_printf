/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:01:35 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/30 20:38:26 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char *str, int *idx, va_list ap)
{
	*idx += 1;
	if (str[*idx] == 'c')
		return (ft_printf_putchar(va_arg(ap, int)));
	else if (str[*idx] == 's')
		return (ft_printf_putstr(va_arg(ap, char *)));
	else if (str[*idx] == 'p')
		return (ft_printf_putmemory(va_arg(ap, unsigned long long)));
	else if (str[*idx] == 'd' || str[*idx] == 'i')
		return (ft_printf_putnbr(va_arg(ap, int)));
	else if (str[*idx] == 'u')
		return (ft_printf_putunbr(va_arg(ap, unsigned int)));
	else if (str[*idx] == 'x')
		return (ft_printf_putxnbr(va_arg(ap, unsigned int) \
								, "0123456789abcdef"));
	else if (str[*idx] == 'X')
		return (ft_printf_putxnbr(va_arg(ap, unsigned int) \
								, "0123456789ABCDEF"));
	else if (str[*idx] == '%')
		return (ft_printf_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		len;
	int		tmp;

	va_start(ap, str);
	idx = 0;
	len = 0;
	tmp = 0;
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			tmp = check_type(str, &idx, ap);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
			len += ft_printf_putchar(str[idx]);
		idx++;
	}
	va_end(ap);
	return (len);
}
