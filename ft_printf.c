/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:56:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/27 17:47:55 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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

int	cpy_type(va_list ap, t_backup *backup, char *ap_str)
{
	if (*ap_str == 'c')
		return (ft_putchar (va_arg (ap, int), backup));
	else if (*ap_str == 's')
		return (ft_putstr (va_arg (ap, char *), backup));
	else if (*ap_str == 'p')
		return (ft_putnbr_base_m ((unsigned long long)va_arg
				(ap, void *), backup));
	else if (*ap_str == 'd' || *ap_str == 'i')
		return (ft_putnbr_p ((long long)va_arg (ap, int), backup));
	else if (*ap_str == 'u')
		return (ft_putnbr_p ((unsigned int)va_arg (ap, int), backup));
	else if (*ap_str == 'x')
		return (ft_putnbr_base ((unsigned int)va_arg (ap, int), backup, 0));
	else if (*ap_str == 'X')
		return (ft_putnbr_base ((unsigned int)va_arg (ap, int), backup, 1));
	else if (*ap_str == '%')
		return (ft_putchar ('%', backup));
	return (0);
}

void	ft_rev_int_tab(char *tab, int size)
{
	int	tmp;
	int	j;
	int	i;

	i = size / 2;
	j = 0;
	while (i > 0)
	{
		tmp = tab[size - 1];
		tab[size - 1] = tab[j];
		tab[j] = tmp;
		size--;
		i--;
		j++;
	}
}

int	va_printf(va_list ap, t_backup *backup, char *original)
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
		backup->string = ft_strjoin (backup,
				ft_strdup (&ap_str[count]), i - count);
		if (backup->string == NULL)
			return (0);
		backup->s_idx = backup->s_idx + (i - count);
		if (ap_str[i] == '%')
		{
			if (is_type ((ap_str[++i])))
				cpy_type (ap, backup, &ap_str[i]);
			i++;
		}
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	static t_backup	*backup;
	int				i;

	backup = (t_backup *)malloc (sizeof (t_backup));
	if (backup == NULL)
		return (0);
	backup->string = (char *)malloc (1);
	if (!backup->string)
		return (0);
	backup->string[0] = '\0';
	backup->s_idx = 0;
	i = 0;
	va_start (ap, str);
	va_printf (ap, backup, (char *)str);
	va_end (ap);
	i = write (1, backup->string, backup->s_idx);
	free (backup->string);
	free (backup);
	return (i);
}
