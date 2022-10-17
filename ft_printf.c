/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:56:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/16 18:19:38 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
flags check_flags(t_flag **flag, char c)
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
	return (check_enum (c));
}

flags check_enum (char c)
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
			if (is_type (++*ap_str))
				cpy_type (ap,&str[str_len]);
			else
				cpy_flags (ap, &str[str_len]);
		}
		str[str_len++] = *ap_str++;
	}
}
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	str[INT_MAX];

	va_start (ap, str);
	va_printf (ap, str);
	va_end (ap);
}
