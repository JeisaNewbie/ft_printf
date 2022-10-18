/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:38:41 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/18 16:17:00 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# include "ft_hexa.c"
# include "ft_printf_utils.c"

/*typedef struct s_flag{
	int	left;
	int	zeropad;
	int	precision;
	int	altform;
	int	blank;
	int	sign;
}t_flag

typedef enum {
	c = char,
	s = char *,
	p = void *,
	d = int,
	i = int,
	u = int,
	x = int,
	X = int,
	% = char
} types

typedef enum {
	left = 1,
	zeropad,
	precision,
	altform,
	blank,
	sign
} flags
*/
int		ft_printf(const char *str, ...);
void    va_printf(va_list ap, char *str);
void    cpy_type (va_list ap, char *str, int *str_len, char **ap_str);
int		is_type(char c);
//types	check_tnum (char type);
//flags	check_fnum (char c);
//flags	check_flags(t_flag **flag, char c);
void    recursion(long long nb, char *str, int *str_len, char *base);
void    ft_putnbr_h(long long n, char *str, int *str_len, char *base);
void    ft_putnbr_base(long long nbr, char *str, int *str_len, int upper);
void    hexa_m(unsigned long long decimal, char *str, int *str_len, char *base);
void	ft_putstr(char *s, char *str, int *str_len);
void	ft_putchar(char c, char *str, int *str_len);
void	recursion_p(long long n, char *str, int *str_len);
void	ft_putnbr(long long n, char *str, int *str_len);
void    ft_putnbr_base_m(unsigned long long nbr, char *str, int *str_len);

#endif
