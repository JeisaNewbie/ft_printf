/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:56:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/11/30 15:00:02 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recursion_h(unsigned long long nb, char *tmp, int *i, char *base)
{
	if (nb == 0)
		return ;
	recursion_h (nb / 16, tmp, i, base);
	tmp[(*i)++] = base[nb % 16];
}

int	ft_putnbr_h(unsigned int n, t_backup *backup, char *base)
{
	char			*tmp;
	int				i;

	tmp = (char *)malloc (sizeof (char) * 17);
	if (tmp == NULL)
		return (0);
	i = 0;
	if (n == 0)
		tmp[i++] = '0';
	recursion_h (n, tmp, &i, base);
	tmp[i] = '\0';
	backup->string = ft_strjoin (backup, tmp, i);
	free (tmp);
	if (backup->string == NULL)
		return (0);
	backup->s_idx = backup->s_idx + i;
	return (1);
}

int	ft_putnbr_base(unsigned int nbr, t_backup *backup, int upper)
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
		number = ft_putnbr_h (nbr, backup, upper_hexa);
	else
		number = ft_putnbr_h (nbr, backup, lower_hexa);
	return (number);
}

int	hexa_m(unsigned long long decimal, t_backup *backup, char *base)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc (sizeof (char) * 19);
	if (tmp == NULL)
		return (0);
	i = 2;
	tmp[0] = '0';
	tmp[1] = 'x';
	if (decimal == 0)
		tmp[i++] = '0';
	if (decimal > 0)
		recursion_h(decimal, tmp, &i, base);
	tmp[i] = '\0';
	backup->string = ft_strjoin (backup, tmp, i);
	free (tmp);
	if (backup->string == NULL)
		return (0);
	backup->s_idx = backup->s_idx + i;
	return (1);
}
