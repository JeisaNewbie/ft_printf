/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:56:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/17 19:12:39 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recursion(long long nb, char *str, int *str_len, char *base)
{
	if (nb == 0)
		return ;
	recursion (nb / 16, str, str_len, base);
	str[*str_len] = base[nb % 16];
	(*str_len)++;
}

void	ft_putnbr_h(long long n, char *str, int *str_len, char *base)
{
	if (n == 0)
	{
		str[*str_len] = '0';
		(*str_len)++;
	}
	else if (n < 0)
	{
		n *= -1;
		str[*str_len] = '-';
		(*str_len)++;
		recursion (n, str, str_len, base);
	}
	else
		recursion (n, str, str_len, base);
}

void	ft_putnbr_base(int nbr, char *str, int *str_len, int upper)
{
	char	upper_hexa[16];
	char	lower_hexa[16];
	int		number;

	number = 0;
	while (number < 10)
	{
		upper_hexa[number] = number;
		lower_hexa[number] = number;
		number++;
	}
	while (number < 16)
	{
		upper_hexa[number] = number + 55;
		lower_hexa[number] = number + 87;
		number++;
	}
	if (upper)
		ft_putnbr_h ((long long)nbr, str, str_len, upper_hexa);
	else if (upper == 0)
		ft_putnbr_h ((long long)nbr, str, str_len, lower_hexa);
	else
		hexa_m ((unsigned long long)nbr, str, str_len, lower_hexa);
}

void	hexa_m(unsigned long long decimal, char *str, int *str_len, char *base)
{
	str[(*str_len)++] = '0';
	str[(*str_len)++] = 'x';
	if (decimal == 0)
	{
		str[*str_len] = '0';
		(*str_len)++;
		return ;
	}
	while (decimal > 0)
	{
		str[(*str_len)++] = base[decimal % 16];
		decimal = decimal / 16;
	}
}
