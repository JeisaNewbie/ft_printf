#include "ft_printf.h"

void	ft_putnbr_base_m(unsigned long long nbr, static char *string)
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
	hexa_m ((unsigned long long)nbr, string, lower_hexa);
}

void	recursion_p(long long n, char *tmp, int *i)
{
	char	c;

	if (n == 0)
		return ;
	recursion_p (n / 10, tmp, i);
	c = (n % 10) + '0';
	tmp[*i++] = c;
}

void	recursion_n(long long n, char *tmp, int *i)
{
	tmp[*i++] = '-';
	if (n == -2147483648)
	{
		tmp[*i++] = '2';
		n = 147483648;
	}
	n *= -1;
	recursion_p (n, tmp, i);
}

int	ft_putnbr_p(long long n, static char *string)
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
		recursion_n (n, tmp, &i);
	else if (n > 0)
		recursion_p (n, tmp, &i);
	tmp[i] = '\0';
	string = ft_strjoin (string, tmp);
	if (!string)
		return (0);
	return (1);
}

int	ft_putstr(char *s, static char *string)
{
	char	*tmp;
	int		len_s;

	len_s = ft_strlen (s);
	tmp = (char *)malloc (sizeof (char) * (len_s + 1));
	if (tmp == NULL)
		return (0);
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	string = ft_strjoin (string, tmp);
	if (string == NULL)
		return (0);
	return (1);
}
