/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:53:47 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/20 18:42:43 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	check_string(const char *str, long minus);

long	minus_atoi(const char *str, long minus)
{
	if ((9 <= *str && *str <= 13) || *str == ' ')
	{
		while (((9 <= *str && *str <= 13) || *str == ' ') && *str != '\0')
			str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	if ('0' <= *str && *str <= '9')
		return (minus * check_string(str, minus));
	return (0);
}

long	check_string(const char *str, long minus)
{
	long	return_atoi;
	int		count;

	return_atoi = 0;
	count = 0;
	while (*str != '\0' && ('0' <= *str && *str <= '9'))
	{
		return_atoi = return_atoi * 10 + (*str - '0');
		count++;
		if (count >= 19 && (*str - '0') > 7 && minus == 1)
			return (-1);
		else if (count >= 19 && (*str - '0') > 8 && minus == -1)
			return (0);
		str++;
	}
	return (return_atoi);
}

int	ft_atoi(const char *str)
{
	return ((int)minus_atoi(str, 1));
}
