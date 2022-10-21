/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:56:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/21 21:19:33 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*flags	check_flags(t_flag **flag, char c)
{
	if (c == '-')
		(*flag)->left = 1;
	if (c == '0')
		(*flag)->zeropad = 1;
	if (c == '.')
		(*flag)->precision = 1;
	if (c == '#')
		(*flag)->altform = 1;
	if (c == ' ')
		(*flag)->blank = 1;
	if (c == '+')
		(*flag)->sign = 1;
	return (check_fnum (c));
}

flags	check_fnum(char c)
{
	if (c == '-')
		return (1);
	if (c == '0')
		return (2);
	if (c == '.')
		return (3);
	if (c == '#')
		return (4);
	if (c == ' ')
		return (5);
	if (c == '+')
		return (6);
}

types	check_tnum(char type)
{
	types	tnum;

	if (type == 'c')
		return (1);
	if (type == 's')
		return (2);
	if (type == 'p')
		return (3);
	if (type == 'd')
		return (4);
	if (type == 'i')
		return (5);
	if (type == 'u')
		return (6);
	if (type == 'd')
		return (7);
	if (type == 'x')
		return (8);
	if (type == 'X')
		return (9);
	if (type == '%')
		return (10);
}
*/
int	is_type(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int	cpy_type(va_list ap, static char *string, int *i, char **ap_str)
{
	if (**ap_str == 'c')
		if (!ft_putchar (va_arg (ap, int), string))
			return (0);
	else if (**ap_str == 's')
		if (!ft_putstr (va_arg (ap, char *), string))
			return (0);
	else if (**ap_str == 'p')
		if (!ft_putnbr_base_m ((unsigned long long)va_arg (ap, void *), string))
			return (0);
	else if (**ap_str == 'd' || **ap_str == 'i')
		if (!ft_putnbr_p ((long long)va_arg (ap, int), string))
			return (0);
	else if (**ap_str == 'u')
		if (!ft_putnbr_p ((unsigned int)va_arg (ap, int), string))
			return (0);
	else if (**ap_str == 'x')
		if (!ft_putnbr_base ((long long)va_arg (ap, int), string, 0))
			return (0);
	else if (**ap_str == 'X')
		if (!ft_putnbr_base ((long long)va_arg (ap, int), string, 1))
			return (0);
	else if (**ap_str == '%')
		if (!ft_putchar ('%', string))
			return (0);
	return (1);
}

int	va_printf(va_list ap, char **string, char *original)
{
	char	*ap_str;
	int		i;
	int		count;

	i = 0;
	ap_str = original;
	while (ap_str[i] != '\0')
	{
		count = i;
		while (ap_str[i] != '%' && ap_str[i] != '\0')
			i++;
		string = ft_strjoin (string, ft_strdup (&ap_str[count]));
		if (string == NULL)
			return (0);
		if (ap_str[i] == '%')
		{
			if (is_type ((ap_str[++i])))
				cpy_type (ap, string, &i, &ap_str[i]);
			i++;
		}
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	static char		*string;
	int				i;

	i = 0;
	string = "";
	va_start (ap, str);
	va_printf (ap, &string, (char *)str);
	va_end (ap);
	while (string[i])
		write (1, &string[i++], 1);
	return (i);
}
