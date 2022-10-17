/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:56:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/17 19:27:26 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

void	cpy_type(va_list ap, char *str, int *str_len, char **ap_str)
{
	if (**ap_str == 'c')
		ft_putchar (va_arg (ap, char), str, str_len);
	if (**ap_str == 's')
		ft_putstr (va_arg (ap, char *), str, str_len);
	if (**ap_str == 'p')
		ft_putnbr_base (va_arg (ap, void *), str, str_len, 2);
	if (**ap_str == 'd' || **ap_str == 'i')
		ft_putnbr (va_arg (ap, int), str, str_len);
	if (**ap_str == 'u')
		ft_putnbr ((unsigned int)va_arg (ap, int), str, str_len);
	if (**ap_str == 'x')
		ft_putnbr_base (va_arg (ap, int), str, str_len, 0);
	if (**ap_str == 'X')
		ft_putnbr_base (va_arg (ap, int), str, str_len, 1);
	if (**ap_str == '%')
		str[*str_len] = '%';
	(*ap_str)++;
}

void	va_printf(va_list ap, char *str)
{
	char	*ap_str;
	int		str_len;
	int		ap_i;

	ap_str = ap - 1;
	str_len = 0;
	ap_i = 0;
	while (*ap_str != '\0')
	{
		if (*ap_str == '%')
		{
			if (is_type (*(++ap_str)))
				cpy_type (ap, str, &str_len, &ap_str);
			//else
			//	cpy_flags (ap, str, &str_len);
		}
		str[str_len++] = *ap_str;
		ap_str++;
	}
	str[str_len] = '\0';
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	str[INT_MAX];
	int		i;

	i = 0;
	va_start (ap, str);
	va_printf (ap, str);
	va_end (ap);
	while (str[i])
		write (1, str[i++], 1);
	return (i);
}
