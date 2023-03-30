/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:42:54 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/28 19:49:56 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		check_type(const char *str, int *idx, va_list ap);
int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *s);
int		ft_printf_putnbr(int nb);
int		ft_printf_putunbr(unsigned int unbr);
size_t	ft_strlen(const char *s);
int		ft_printf_putxnbr(unsigned int unbr, char *base);
int		ft_printf_puthex(int n);
int		ft_printf_putmemory(unsigned long long addr);

#endif