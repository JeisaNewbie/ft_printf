#include "ft_printf.h"
void	ft_putnbr_base_m(unsigned long long nbr, char *str, int *str_len)
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
	hexa_m ((unsigned long long)nbr, str, str_len, lower_hexa);
}

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

void	ft_putchar(char c, char *str, int *str_len)
{
	str[*str_len] = c + '0';
	(*str_len)++;
}

void	ft_putstr(char *s, char *str, int *str_len)
{
	while (*s)
	{
		str[*str_len] = *s;
		(*str_len)++;
		s++;
	}
}
