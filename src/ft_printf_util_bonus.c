/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:09:27 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/27 20:19:27 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_nbrlen(int nbr, int basenum)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len++;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= basenum;
		len++;
	}
	return (len);
}

int	check_unbrlen(unsigned int nbr, int basenum)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= basenum;
		len++;
	}
	return (len);
}

int	ft_printf_atoi(const char *str, int *idx)
{
	int	result;
	int	pm;
	int	flag;

	result = 0;
	pm = 1;
	flag = 0;
	while ((str[*idx] >= 9 && str[*idx] <= 13) || str[*idx] == ' ')
		*idx += 1;
	while ((str[*idx] == '-' || str[*idx] == '+') && !flag)
	{
		if (str[*idx] == '-')
			pm = pm * -1;
		flag = 1;
		*idx += 1;
	}
	while (str[*idx] >= '0' && str[*idx] <= '9')
	{
		result = result * 10 + (str[*idx] - '0');
		*idx += 1;
	}
	if (result != 0)
		result *= pm;
	return (result);
}
