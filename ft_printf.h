/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:38:41 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/27 17:23:41 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_backup{
	char	*string;
	int		s_idx;
}	t_backup;

int		ft_printf(const char *str, ...);
int		va_printf(va_list ap, t_backup *backup, char *original);
int		cpy_type(va_list ap, t_backup *backup, char *ap_str);
int		is_type(char c);
void	recursion_h(unsigned long long nb, char *tmp, int *i, char *base);
int		ft_putnbr_h(unsigned int n, t_backup *backup, char *base);
int		ft_putnbr_base(unsigned int nbr, t_backup *backup, int upper);
int		hexa_m(unsigned long long decimal, t_backup *backup, char *base);
int		ft_putnbr_base_m(unsigned long long nbr, t_backup *backup);
void	recursion_p(long long n, char *tmp, int *i);
void	recursion_n(long long n, char *tmp, int *i);
int		ft_putnbr_p(long long n, t_backup *backup);
void	ft_rev_int_tab(char *tab, int size);
int		ft_putchar(char c, t_backup *backup);
int		ft_putstr(char *s, t_backup *backup);
char	*ft_strjoin(t_backup *backup, char *s2, int s2_idx);

#endif
