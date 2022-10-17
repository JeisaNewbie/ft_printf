/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:35:29 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 21:34:26 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp1;
	char	*tmp2;
	int		from_l;
	int		i;

	i = 0;
	from_l = 0;
	if (dst == 0 && src == 0)
		return (dst);
	if (dst > src)
	{
		i = len - 1;
		from_l = 1;
	}
	tmp1 = (char *)src;
	tmp2 = (char *)dst;
	while (len--)
	{
		tmp2[i] = tmp1[i];
		if (from_l == 1)
			i--;
		else
			i++;
	}
	return (dst);
}
