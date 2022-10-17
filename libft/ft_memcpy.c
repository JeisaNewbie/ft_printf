/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:33:47 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 19:23:54 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	if (dst == 0 && src == 0)
		return (dst);
	tmp1 = (char *)dst;
	tmp2 = (char *)src;
	i = 0;
	while (n)
	{
		tmp1[i] = tmp2[i];
		i++;
		n--;
	}
	return (dst);
}
