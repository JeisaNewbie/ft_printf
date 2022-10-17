/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:36:58 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 20:30:29 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	unsigned char	*tmp;

	a = (unsigned char)c;
	tmp = (unsigned char *)b;
	while (len)
	{
		*tmp = a;
		tmp++;
		len--;
	}
	return (b);
}
