/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:38:15 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/17 19:09:06 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	recursion_p(long long n, char *str, int *str_len)
{
	char	c;

	if (n == 0)
		return ;
	recursion_p (n / 10, str, str_len);
	c = (n % 10) + '0';
	str[*str_len] = c;
	(*str_len)++;
}

void	ft_putnbr(long long n, char *str, int *str_len)
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
		if (n == -2147483648)
		{
			str[*str_len] = '2';
			(*str_len)++;
			recursion_p (147483648, str, str_len);
			return ;
		}
		recursion_p (n, str, str_len);
	}
	else
		recursion_p (n, str, str_len);
}
