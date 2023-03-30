/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:47:32 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/28 19:49:54 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

int		check_type_bonus(const char *str, int *idx, va_list ap, char flag);
int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *s);
int		ft_printf_putnbr(int nb);
int		ft_printf_putunbr(unsigned int unbr);
size_t	ft_strlen(const char *s);
int		ft_printf_putxnbr(unsigned int unbr, char *base);
int		ft_printf_puthex(int n);
int		ft_printf_putmemory(unsigned long long addr);
int		check_nbrlen(int nbr, int basenum);
int		check_unbrlen(unsigned int nbr, int basenum);
int		ft_printf_atoi(const char *str, int *idx);
int		ft_printf_onlynbr(int nb);
int		ft_printf_putnbr_format(int nb, char sign);
int		ft_printf_zero_int(int nb, int zerosize);
int		ft_printf_zero_uint(unsigned int nb, int zerosize);
int		ft_printf_zero_hex(unsigned int nb, int zerosize, char xsize);

#endif