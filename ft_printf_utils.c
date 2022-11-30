/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:54:13 by jhwang2           #+#    #+#             */
/*   Updated: 2022/11/30 15:00:04 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_m(unsigned long long nbr, t_backup *backup)
{
	char	lower_hexa[16];
	int		number;

	number = 0;
	while (number < 10)
	{
		lower_hexa[number] = number + '0';
		number++;
	}
	while (number < 16)
	{
		lower_hexa[number] = number + 87;
		number++;
	}
	number = hexa_m (nbr, backup, lower_hexa);
	return (number);
}

void	recursion_p(long long n, char *tmp, int *i)
{
	char	c;

	if (n == 0)
		return ;
	recursion_p (n / 10, tmp, i);
	c = (n % 10) + '0';
	tmp[(*i)++] = c;
}

void	recursion_n(long long n, char *tmp, int *i)
{
	tmp[(*i)++] = '-';
	if (n == -2147483648)
	{
		tmp[(*i)++] = '2';
		n = -147483648;
	}
	n *= -1;
	recursion_p (n, tmp, i);
}

int	ft_putnbr_p(long long n, t_backup *backup)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc (sizeof (char) * 12);
	if (tmp == NULL)
		return (0);
	i = 0;
	if (n == 0)
		tmp[i++] = '0';
	else if (n < 0)
		recursion_n (n, tmp, &i);
	else
		recursion_p (n, tmp, &i);
	tmp[i] = '\0';
	backup->string = ft_strjoin (backup, tmp, i);
	free (tmp);
	if (backup->string == NULL)
		return (0);
	backup->s_idx = backup->s_idx + i;
	return (1);
}
