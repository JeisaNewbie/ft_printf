/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:38:41 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/21 21:19:36 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

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
int		va_printf(va_list ap, char **string, char *original);
int		cpy_type (va_list ap, static char *string, int *i, char **ap_str);
int		is_type(char c);
//types	check_tnum (char type);
//flags	check_fnum (char c);
//flags	check_flags(t_flag **flag, char c);
void    recursion_ph(long long nb, char *tmp, int *i, char *base);
void    recursion_nh(long long nb, char *tmp, int *i, char *base);
int		ft_putnbr_h(long long n, static char *string, char *base);
void    ft_putnbr_base(long long nbr, static char *string, int upper);
int		hexa_m(unsigned long long decimal, static char *string, char *base);
int		ft_putstr(char *s, static char *string);
void	recursion_p(long long n, char *tmp, int *i);
void    recursion_n(long long n, char *tmp, int *i);
int		ft_putnbr_p(long long n, static char *string);
void    ft_putnbr_base_m(unsigned long long nbr, static char *string);

#endif
