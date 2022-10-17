/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:35:00 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 21:38:47 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	int				i;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n && (tmp1[i] == tmp2[i]))
	{
		i++;
		n--;
	}
	if (n == 0)
		return (tmp1[i - 1] - tmp2[i - 1]);
	else
		return (tmp1[i] - tmp2[i]);
}
