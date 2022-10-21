/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:56:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/21 21:19:41 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recursion_ph(long long nb, char *tmp, int *i, char *base)
{
	if (nb == 0)
		return ;
	recursion_ph (nb / 16, tmp, i, base);
	tmp[*i++] = base[nb % 16];
}

void	recursion_nh(long long nb, char *tmp, int *i, char *base)
{
	tmp[*i++] = '-';
	n *= -1;
	recursion_ph (n, tmp, i, base);
}

int	ft_putnbr_h(long long n, static char *string, char *base)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc (sizeof (char) * 12);
	if (tmp == NULL)
		return (0);
	i = 0;
	if (n == 0)
		tmp[i++] = '0';
	if (n < 0)
		recursion_nh (n, tmp, &i, base);
	else if (n > 0)
		recursion_ph (n, tmp, &i, base);
	tmp[i] = '\0';
	string = ft_strjoin (string, tmp);
	if (!string)
		return (0);
	return (1);
}

void	ft_putnbr_base(long long nbr, static char *string, int upper)
{
	char	upper_hexa[16];
	char	lower_hexa[16];
	int		number;

	number = 0;
	while (number < 10)
	{
		upper_hexa[number] = number + '0';
		lower_hexa[number] = number + '0';
		number++;
	}
	while (number < 16)
	{
		upper_hexa[number] = number + 55;
		lower_hexa[number] = number + 87;
		number++;
	}
	if (upper)
		ft_putnbr_h (nbr, string, upper_hexa);
	else
		ft_putnbr_h (nbr, string, lower_hexa);
}

int	hexa_m(unsigned long long decimal, static char *string, char *base)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc (sizeof (char) * 19);
	if (tmp == NULL)
		return (NULL);
	i = 2;
	str[0] = '0';
	str[1] = 'x';
	if (decimal == 0)
		tmp[i++] = '0';
	while (decimal > 0)
	{
		tmp[i++] = base[decimal % 16];
		decimal = decimal / 16;
	}
	tmp[i] = '\0';
	string = ft_strjoin (string, tmp);
	if (!string)
		return (0);
	return (1);
}
